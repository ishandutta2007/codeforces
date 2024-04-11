#include <cstdio>
#include <cstring>

const int N = 1000005;
const int mo = 1000000009;
long long prev[N], back[N];
long long pow[N];
long long target;
char s0[N], s1[N];
int ans[N];
int cans;
int toint(char c)
{return c - 'a';}
int main()
{
    gets(s0 + 1);
    gets(s1 + 1);
    int n = strlen(s0 + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; ++i) pow[i] = pow[i - 1] * 26 % mo;
    for (int i = 1; i <= n; ++i) {
        prev[i] = prev[i - 1] * 26 + toint(s0[i]);
        prev[i] %= mo;
    }
    for (int i = n; i >= 1; --i) {
        back[i] = back[i + 1] + toint(s0[i]) * pow[n - i];
        back[i] %= mo;
    }
    for (int i = 1; i <= n - 1; ++i) {
        target = target * 26 + toint(s1[i]);
        target %= mo;
    }
    for (int i = 1; i <= n; ++i) {
        long long cur = (prev[i - 1] * pow[n - i] + back[i + 1]) % mo;
        if (cur == target) ans[++cans] = i;
    }
    printf("%d\n", cans);
    for (int i = 1; i <= cans; ++i) printf("%d%c", ans[i], i == cans ? '\n' : ' ');
}