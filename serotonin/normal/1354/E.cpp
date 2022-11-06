#include <bits/stdc++.h>
using namespace std;
const int sz = 5005;

int tot, one, col[sz], id[sz], cut[sz], dp[sz][sz], ans[sz];
vector <int> g[sz], red, blue;

bool dfs(int u, int f = 0)
{
    tot++;
    if(f) one++;
    col[u] = f + 1;
    id[u] = blue.size();

    f ^= 1;
    bool yes = 1;
    for(int v : g[u]) {
        if(!col[v]) yes &= dfs(v, f);
        else if(col[v] - 1 != f) return 0;
    }
    return yes;
}

int fnc(int rem, int pos)
{
    if(rem < 0) return 0;
    if(pos < 0) {
        if(!rem) return 1;
        return 0;
    }
    if(dp[rem][pos] < 0) {
        dp[rem][pos] = 0;
        int x = fnc(rem - blue[pos], pos - 1);
        if(x) return dp[rem][pos] = 1;
        int y = fnc(rem - red[pos], pos - 1);
        if(y) return dp[rem][pos] = 2;
    }
    return dp[rem][pos];
}

void go(int rem, int pos)
{
    if(pos < 0) return;
    if(dp[rem][pos] == 1) {
        cut[pos] = 1;
        go(rem - blue[pos], pos - 1);
    }
    else {
        cut[pos] = 2;
        go(rem - red[pos], pos - 1);
    }
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    cin >> a >> b >> c;
    while(m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++) if(!col[i]) {
        one = tot = 0;
        if(!dfs(i)) {
            puts("NO");
            return 0;
        }
        blue.push_back(one), red.push_back(tot - one);
    }

    memset(dp, -1, sizeof(dp));
    int ok = fnc(b, blue.size() - 1);

    if(!ok) {
        puts("NO");
        return 0;
    }

    puts("YES");
    go(b, blue.size() - 1);

    for(int i=1, j=0; i<=n; i++) {
        if(cut[id[i]] ^ col[i]) printf("2");
        else {
            if(j++ < a) printf("1");
            else printf("3");
        }
    }
}