#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

ll p = (int)1e6 + 3;
struct HASH{
    size_t operator()(const vector<int> &v)const{
        ll res = 0;
        for(int x : v) {
            res *= p;
            res += x;
        }
        return hash<ll>()(res);
    }
};
int n, m, k;
unordered_map<vector<int>, int, HASH> mp;
int lab[N], val[N];
vector<int> G[N], nG[N];

void dfs(int v, int p, int x) {
    val[v] = x;
    for(int nxt : nG[v]) {
        if(nxt != p) dfs(nxt, v, x + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        G[i].push_back(i);
        sort(G[i].begin(), G[i].end());
        int &x = mp[G[i]];
        if(x == 0) x = ++k;
        lab[i] = x;
    }
    for(int i = 0; i < n; i++) {
        for(int nxt : G[i]) {
            if(lab[i] != lab[nxt]) nG[lab[i]].push_back(lab[nxt]);
        }
    }
    if(k == 1) {
        val[1] = 1;
    }
    else {
        int beg = -1;
        for(int i = 1; i <= k; i++) {
            sort(nG[i].begin(), nG[i].end());
            nG[i].erase(unique(nG[i].begin(), nG[i].end()), nG[i].end());
            if(nG[i].size() >= 3) return cout << "NO" << endl, 0;
            if(nG[i].size() == 1) beg = i;
        }
        if(beg == -1) return cout << "NO" << endl, 0;
        dfs(beg, -1, 1);
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << val[lab[i]] << " ";
    }
    cout << endl;

}