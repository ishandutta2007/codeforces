#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); ++(i))

bitset<423> ans[423], p[423][26];
char q;

int main() {
    int n, m; cin >> n >> m;
    rep(i, n) rep(j, m) scanf(" %c", &q), p[i][q-'a'][j] = ans[i][j] = 1;
    int r, c; cin >> r >> c;
    rep(i, r) rep(j, c) if (scanf(" %c", &q), q != '?') rep(k, n) ans[(k+n-i%n)%n] &= p[k][q-'a']>>j%m|p[k][q-'a']<<m-j%m;
    rep(i, n) rep(j, m) printf("%d%s", (int)ans[i][j], j==m-1?"\n":"");
    return 0;
}