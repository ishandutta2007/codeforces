#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 100;

int N;
vector<int> adj[MAXN];

int deg[MAXN];
bool rem[MAXN];

bool bot[MAXN];
bool below[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    queue<int> leaf;

    for (int i = 0; i < N; i++) {
        deg[i] = adj[i].size();
        if(deg[i] == 1) leaf.push(i);
    }

    while(!leaf.empty()) {
        int cons = leaf.front();
        leaf.pop();

        // we only want to contract this upward if the parent has degree 2
        int neigh = -1;
        for (int vert : adj[cons]) {
            if(!rem[vert]) {
                neigh = vert;
                break;
            }
        }

        if(deg[neigh] != 2) continue;

        rem[cons] = true;
        deg[neigh] = 1;

        leaf.push(neigh);
    }

    for (int i = 0; i < N; i++) {
        if(rem[i] || deg[i] == 1) continue;

        int bot = 0;
        int non = 0;

        for (int vert : adj[i]) {
            if(rem[vert]) continue;
            if(deg[vert] == 1) bot++;
            else non++;
        }

        if(bot <= 2 && non <= 1) {
            below[i] = true;
        }
    }

    for (int i = 0; i < MAXN; i++) {
        if(below[i] || rem[i] || deg[i] == 1) continue;

        int top = 0;
        for (int vert : adj[i]) {
            if(rem[vert] || deg[vert] == 1 || below[vert]) continue;
            top++;
        }

        if(top > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}