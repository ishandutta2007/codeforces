#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int MAXN = 8e5 + 100;

ll N;
vector<int> adj[MAXN];
ll subt[MAXN];

ll calc(int loc, int par) {
    subt[loc] = 1;
    vector<int> child;
    
    ll res = 0;

    for (int ch : adj[loc]) {
        if (ch != par) {
            res += calc(ch, loc);
            subt[loc] += subt[ch];
            child.push_back(ch);
        }
    }

    ll path = subt[loc] * subt[loc];

    for (int ch : child) {
        path -= subt[ch] * subt[ch];
    }

    path = (path - 1) / 2;

    ll pathup = subt[loc] * (N - subt[loc]);

    return res + path * path + 2 * path * pathup;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    ll pair = N * (N - 1) / 2;
    ll soln = pair * pair;

    cout << soln - calc(0, -1) << endl;
}