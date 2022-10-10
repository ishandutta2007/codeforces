#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int rep[MAXN], sz[MAXN], cnt[MAXN][26];

int find(int u) {
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    rep[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    iota(rep, rep + n, 0);
    fill(sz, sz + n, 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 26; j++)
            cnt[i][j] = 0;
    for(int i = 0; i + k < n; i++)
        join(i, i + k);
    for(int i = 0; i < n - 1 - i; i++)
        join(i, n - 1 - i);
    for(int i = 0; i < n; i++) {
        int u = find(i);
        cnt[u][s[i] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int s = sz[i], m = 0;
        //cout << i << " " << s << endl;
        for(int c = 0; c < 26; c++)
            m = max(m, cnt[i][c]);
        ans += (s - m);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}