#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LCM = 2520;
const int MAXN = LCM * 1000 + 5;
int f[MAXN], mark[MAXN], k[1005];
vector<int> adj[1005];

void dfs(int s) {
    if(mark[s] > 0)
        return;
    if(mark[s] == 0) {
        int cur = f[s];
        set<int> S;
        S.insert(s / LCM);
        while(cur != s) {
            S.insert(cur / LCM);
            cur = f[cur];
        }
        int sz = S.size();
        cur = f[s];
        while(cur != s) {
            mark[cur] = sz;
            cur = f[cur];
        }
        mark[s] = sz;
    }
    if(mark[s] > 0)
        return;
    mark[s] = 0;
    if(mark[f[s]] <= 0)
        dfs(f[s]);
    if(mark[s] == 0)
        mark[s] = mark[f[s]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> k[i];
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while(m--) {
            int x;
            cin >> x;
            --x;
            adj[i].push_back(x);
        }
    }
    int num_v = LCM * n;
    for(int v = 0; v < n; v++) {
        for(int l = 0; l < LCM; l++) {
            int t = (l + k[v]) % (int)adj[v].size();
            if(t < 0)
                t += (int)adj[v].size();
            t = adj[v][t];
            int nl = (l + k[v]) % LCM;
            if(nl < 0)
                nl += LCM;
            f[LCM*v + l] = LCM*t + nl;
        }
    }
    fill(mark, mark + num_v, -1);
    for(int i = 0; i < num_v; i++)
        dfs(i);
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y %= LCM;
        if(y < 0)
            y += LCM;
        cout << mark[LCM*x + y] << '\n';
    }
}