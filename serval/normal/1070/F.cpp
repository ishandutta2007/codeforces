#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define N 100005
#define pb push_back
#define F first
#define S second
int a[N], n, k, tot, now, sum, ans, sz[4], up;
std::vector<int> s[4];
inline bool cmp (int x, int y) {return x > y;}
int main ()
{
    scanf("%d", &n);
    fo (i, 1, n)
    {
        int opt, x;
        scanf("%d %d", &opt, &x);
        if (opt == 11) opt = 3;
        if (opt == 10) opt = 2;
        s[opt].push_back(x);
    }
    ans = 0;
    n = s[3].size() - 1;
    fo (i, 0, n)
        ans += s[3][i];
    sz[1] = s[1].size() - 1;
    sz[2] = s[2].size() - 1;
    sz[0] = s[0].size() - 1;
    std::sort(s[1].begin(), s[1].end(), cmp);
    std::sort(s[2].begin(), s[2].end(), cmp);
    up = std::min(sz[1], sz[2]);
    fo (i, 0, up)
        ans += s[1][i] + s[2][i];
    fo (i, up + 1, sz[1]) s[0].pb(s[1][i]);
    fo (i, up + 1, sz[2]) s[0].pb(s[2][i]);
    std::sort(s[0].begin(), s[0].end(), cmp);
    n = std::min(n, (int)(s[0].size() - 1));
    fo (i, 0, n)
        ans += s[0][i];
    printf("%d", ans);
    return 0;
}