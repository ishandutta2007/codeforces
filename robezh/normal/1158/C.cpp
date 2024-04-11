#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;

int T;
int n, nxt[N];
vector<int> G[N];
int ord[N];
int cur_lab;

bool dfs(int v, int lab) {
    if(v == lab) {
        if(ord[v] == -1) ord[v] = cur_lab--;
        return true;
    }
    if(ord[v] == -1) {
        ord[v] = cur_lab--;
    }

    if(G[v].empty()) return true;
    int nxt_v = G[v][0];
    if(nxt_v < lab) return false;
    if(ord[nxt_v] == -1) ord[nxt_v] = cur_lab--;
    int las = nxt_v;
    for(int i = 1; i < G[v].size(); i++) {
        int nxt = G[v][i];
        if(nxt < lab) return false;
        if(!dfs(nxt, las)) return false;
        las = nxt;
    }
    return dfs(nxt_v, lab);
}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i <= n; i++) G[i].clear();
        for(int i = 0; i < n; i++) {
            cin >> nxt[i];
            if(nxt[i] == -1) nxt[i] = i+1;
            else nxt[i] --;
        }
        bool good = true;
        for(int i = 0; i < n; i++) G[nxt[i]].push_back(i);
        int cur = n;
        cur_lab = n;
        fill(ord, ord + n + 1, -1);
        if(!dfs(n, 0)) {
            cout << "-1\n";
            continue;
        }
//        cout << "Case: " << endl;
        for(int i = 0; i < n; i++) cout << ord[i] + 1 << " ";
        cout << "\n";

    }
}