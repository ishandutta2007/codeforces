#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 5;

int n;
int nxt[N];
int vis[N];
int S[N], sz = 0;
vector<int> res;


int dfs(int v) {
    vis[v] = 1;
    S[sz++] = v;
    if(vis[nxt[v]]) {
        int fir = nxt[v];
        while(true) {
            res.push_back(S[--sz]);
            if(res.back() == fir) break;
        }
        return 1;
    }
    if(dfs(nxt[v]) == 1) {
        return 1;
    }
    sz--;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) vis[i] = 0;
        for(int i = 1; i <= n; i++) {
            int a; cin >> a;
            nxt[i] = i - a;
        }
        sz = 0;
        res.clear();
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && dfs(i)) break;
        }

        cout << res.size() << '\n';
        for(int x : res) cout << x << " ";
        cout << '\n';
    }

}