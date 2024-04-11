#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <int> type(n+1), d(n+1, 0);
    vector <vector <int> > p(n+1, vector <int> (18));
    for(int i = 1; i <= n; i ++) {
        cin >> p[i][0] >> type[i];
        if(type[i] == -1) p[i][0] = 0;
        d[i] = d[p[i][0]] + 1;
    }
    for(int i = 1; i < 18; i ++) for(int j = 1; j <= n; j ++) p[j][i] = p[p[j][i-1]][i-1];
    auto anc = [&](int x, int y) {
        for(int i = 31-__builtin_clz(y); i >= 0; i --) if(y >> i & 1) x = p[x][i];
        return x;
    };
    auto lca = [&](int x, int y) {
        if(d[x] > d[y]) x = anc(x, d[x]-d[y]);
        else if(d[y] > d[x]) y = anc(y, d[y]-d[x]);
        if(x == y) return x;
        for(int i = 31 - __builtin_clz(d[x]); i >= 0; i --) if(p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
        return p[x][0];
    };
    vector <int> a(n+1), b(n+1);
    for(int i = 0; i <= n; i ++) a[i] = i, b[i] = i;
    function <int(int)> finda = [&](int x) {return a[x] == x ? x : a[x]=finda(a[x]);};
    function <int(int)> findb = [&](int x) {return b[x] == x ? x : b[x]=findb(b[x]);};
    for(int i = 1; i <= n; i ++) {
        if(type[i] == 0) {
            int x = finda(i);
            int y = finda(p[i][0]);
            a[x] = y;
        }
        if(type[i] == 1) {
            int x = findb(i);
            int y = findb(p[i][0]);
            b[x] = y;
        }
    }
    int q;
    cin >> q;
    while(q --) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            int z = lca(x, y);
            if(x == z && x != y && finda(x) == finda(y)) puts("YES");
            else puts("NO");
        }
        else {
            int z = lca(x, y);
            if(y != z && findb(y) == findb(z) && finda(z) == finda(x)) puts("YES");
            else puts("NO");
        }
    }
}