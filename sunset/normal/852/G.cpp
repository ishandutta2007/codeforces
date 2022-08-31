#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int N = 100010;
typedef long long ll;
int n, m, len, tot, ans, wh[10], p[10];
char s[N];
ll pow[N], a[10], iss[10];
map <ll, int> M;
map <ll, bool> used;
vector <ll> Use;

void check()
{
    for(int i = 1; i <= tot; i++) wh[i] = (iss[i] == 0); wh[tot + 1] = 0;
    for(int i = tot - 1; i > 0; i--) wh[i] += wh[i + 1];

    ll has = 0;
    for(int i = tot; i; i--) has += a[i] * pow[len - p[i] - wh[i] + 1];
    has += a[tot + 1];
    for(int i = 1; i <= tot; i++) has += iss[i] * pow[len - p[i] - wh[i + 1]];

    if (M.find(has) == M.end()) return;
    if (used[has]) return;

    used[has] = 1;
    Use.push_back(has);

    ans += M[has];
}

void dfs(int x)
{
    if (x > tot) {check(); return;}
    for(int i = 0; i <= 5; i++) {iss[x] = i; dfs(x + 1);}
}

int main()
{
    scanf("%d%d", &n, &m);
    pow[0] = 1; for(int i = 1; i <= 100; i++) pow[i] = pow[i - 1] * 6;
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1); ll tmp = 0;
        for(int j = 1; j <= len; j++) tmp = tmp * 6 + s[j] - 'a' + 1;
        M[tmp]++;
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", s + 1);
        len = strlen(s + 1); tot = ans = 0; ll tmp = 0;
        for(int j = 1; j <= len; j++)
            if (s[j] == '?') {p[++tot] = j; a[tot] = tmp; tmp = 0;}
            else tmp = tmp * 6 + s[j] - 'a' + 1;
        a[tot + 1] = tmp;
        dfs(1); printf("%d\n", ans);

        for(int j = 0; j < Use.size(); ++j)
            used[Use[j]] = 0;
        Use.clear();
    }
    return 0;
}