#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int tot, a[20], b[20], n, ans, tmp, vis[200010];
char s[200010];
int bb[200010];
bool no[2000010];
bool fl, v[20];
int vv[100], vl[100];

int num(int x)
{
    int ans = 0;
    while (x) {ans += x % 10; x /= 10;}
    return ans;
}

void wxh(int x)
{
    int tot = 0, d[100];
    while (x) {d[++tot] = x % 10; x /= 10;}
    for(int i = tot; i > 1; i--) printf("%d+", d[i]);
    printf("%d\n", d[1]);
}

void ck(int F)
{
    int ans = 0, now = 0;
    for(int i = 1; i <= tot; i++)
    {
        now = now * 10 + a[i];
        if (v[i]) {ans += now; now = 0;}
    }
    if (num(ans) < 10)
    {
        fl = 1;
        if (!F) return;
        for(int i = 1; i < tot; i++)
        {
            printf("%d", a[i]);
            if (v[i]) printf("+");
        }
        printf("%d\n", a[tot]);
        wxh(ans);
    }
}

void dfs(int dep, int F)
{
    if (fl) return;
    if (dep == tot) {ck(F); return;}
    dfs(dep + 1, F); v[dep] ^= 1; dfs(dep + 1, F);
}

bool check(int x, int F)
{
    tot = 0;
    while (x) {b[++tot] = x % 10; x /= 10;}
    for(int i = 1; i <= tot; i++) a[i] = b[tot - i + 1];
    fl = 0; v[tot] = 1;
    dfs(1, F); return fl;
}

bool nei(int x, int y)
{
    if (x == y) return vv[x] - vl[x] != 1;
    return (abs(vv[x] - vl[y]) != 1 || abs(vl[x] - vv[y]) != 1);
}

void doit(int x, int y)
{
    if (x == y) {vis[vv[x]] = vis[vl[x]] = 1; return;}
    if (abs(vv[x] - vl[y]) != 1) vis[vv[x]] = vis[vl[y]] = 1;
    else vis[vv[y]] = vis[vl[x]] = 1;
}

bool checkk(int x, int len)
{
    int tmp = ans, now = 0;;
    for(int i = 0; i < len; i++) tmp -= bb[x + i], now = now * 10 + bb[x + i];
    if (!no[tmp + now]) return 1; else return 0;
}

int main()
{
    srand(time(0));
    for(int i = 1; i <= 2000000; i++)
        if (!check(i, 0)) no[i] = 1;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) bb[i] = s[i] - '0';
    for(int i = 1; i <= n; i++) ans += s[i] - '0';
    if (no[ans])
    {
        while (no[ans])
        {
            int x = rand() % (n - 1) + 1;
            if (!vis[x - 1] && !vis[x + 1] && !vis[x])
            {
                vis[x] = 1;
                ans += bb[x] * 9;
            }
            if (!no[ans]) break;
            x = rand() % (n - 2) + 1;
            if (!vis[x - 1] && !vis[x + 1] && !vis[x] && !vis[x + 2])
            {
                vis[x] = vis[x + 1] = 1;
                ans += bb[x] * 99 + bb[x + 1] * 9;
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        printf("%c", s[i]);
        if (!vis[i]) printf("+");
    }
    printf("%c\n", s[n]);
    int now = 0; ans = 0;
    for(int i = 1; i <= n; i++)
    {
        now = now * 10 + s[i] - '0';
        if (!vis[i]) {ans += now; now = 0;}
    }
    check(ans, 1);
    return 0;
}