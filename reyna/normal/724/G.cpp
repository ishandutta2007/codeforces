// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define int long long
vector<int> all;
const int N = (int) 1e6 + 6, L = 62, mod = (int) 1e9 + 7;
vector<int> adj[N];
int cnt[L], s[N], t[N], len[N], a[N], mark[N];
vector<int> base;
void add(int x) {
    for (int p : base)
        if (p & -p & x)
            x ^= p;
    if (!x) return;
    for (int &p : base)
        if (x & -x & p)
            p ^= x;
    base.push_back(x);
}
void dfs(int v, int p = -1) {
    all.push_back(v);
    mark[v] = 1;
    for (int e : adj[v]) {
        int u = s[e] ^ t[e] ^ v;
        if (e != p) {
            if (mark[u]) {
                add(a[u] ^ a[v] ^ len[e]);
            } else {
                a[u] = a[v] ^ len[e];
                dfs(u, e);
            }
        }
    }
}
int z[L];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int &u = s[i], &v = t[i], &w = len[i];
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    int sz = 0;
    for (int st = 0; st < n; ++st) if (!mark[st]) {
        base.clear(); all.clear();
        memset(cnt, 0, sizeof cnt);
        memset(z, 0, sizeof z);
        dfs(st);
        int sz = (int) base.size();
        for (int x : base)
            for (int i = L - 1; i >= 0; --i)
                if (x >> i & 1)
                    z[i] = 1;
        for (int v : all)
            for (int i = 0; i < L; ++i)
                if (a[v] >> i & 1)
                    cnt[i]++;
        for (int bit = 0; bit < L; ++bit) {
            int l = cnt[bit];
            int r = (int) all.size() - cnt[bit];
            int cnt0 = l * (l - 1) / 2 + r * (r - 1) / 2; cnt0 %= mod;
            int cnt1 = l * r % mod;
            if (z[bit])
                res += (1ll << sz - 1) % mod * (cnt0 + cnt1) % mod * ((1ll << bit) % mod) % mod;
            else
                res += (1ll << sz) % mod * cnt1 % mod * ((1ll << bit) % mod) % mod;
            res %= mod;
        }
    }
    cout << res % mod << endl;

}