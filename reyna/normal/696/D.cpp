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

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = 205, mod = 0;
string s[N];
int f[N], q[N], cost[N], sz = 1, nxt[N][26];
string str[N];

void ins(string t) {
    int v = 0;
    string cur = "";
    for (int i = 0; i < (int) t.size(); ++i) {
        if (!nxt[v][t[i] - 'a'])
            nxt[v][t[i] - 'a'] = sz++;
        v = nxt[v][t[i] - 'a'];
        cur += t[i];
        str[v] = cur;
    }
}

void build_aho() {
    int h = 0, t = 0;
    for (int i = 0; i < 26; ++i)
        if (nxt[0][i])
            q[t++] = nxt[0][i];
    while (h != t) {
        int v = q[h++];
        for (int i = 0; i < 26; ++i)
            if (nxt[v][i]) {
                q[t++] = nxt[v][i];
                f[nxt[v][i]] = nxt[f[v]][i];
            } else {
                nxt[v][i] = nxt[f[v]][i];
            }
    }
}
int to[N], mat[60][N][N], adj[N][N], st[N][N], c[N][N];
void mul(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            c[i][j] = -1e18;
    for (int i = 0; i < sz; ++i)
        for (int k = 0; k < sz; ++k) if (a[i][k] >= 0) {
            for (int j = 0; j < sz; ++j)
                c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
        }
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l;    
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ins(s[i]);
    }
    build_aho();
    for (int i = 0; i < n; ++i) {
        for (int v = 0; v < sz; ++v) if ((int) s[i].size() <= (int) str[v].size()) {
            int ok = 1;
            for (int p = str[v].size() - s[i].size(); p < str[v].size(); ++p)
                if (str[v][p] != s[i][p - (str[v].size() - s[i].size())])
                    ok = 0;
            if (ok)
                to[v] += cost[i];
        }
    }
    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            st[i][j] = adj[i][j] = -1e18;
   st[0][0] = 0;
   for (int i = 0; i < sz; ++i)
       for (int j = 0; j < sz; ++j)
           for (int k = 0; k < 26; ++k) if (nxt[i][k] == j) {
                adj[i][j] = to[j];
           }
   memcpy(mat[0], adj, sizeof mat[0]);
   for (int i = 0; i < 50; ++i) {
        mul(mat[i], mat[i]);
        memcpy(mat[i + 1], c, sizeof mat[i + 1]);
   }
   for (int i = 0; i < 50; ++i) if (l >> i & 1) {
        mul(st, mat[i]);
        memcpy(st, c, sizeof st);
   }
   int best = 0;
   for (int i = 0; i < sz; ++i)
        best = max(best, st[0][i]);
   cout << best << '\n';
}