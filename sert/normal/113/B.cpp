#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#define N 2020

using namespace std;
const long long p = 31;
const long long mod = 1e9 + 9;

set<int> res[N];
int n, l1, l2;
char s[N], en[N], beg[N];
long long h1, h2, h[N];
long long deg[N];

int main() {
    scanf("%s%s%s", s, beg, en);
    n = strlen(s);
    l1 = strlen(beg);
    l2 = strlen(en);
    int i;
    for (i = 0; i < n; ++i)
        h[i + 1] = (h[i] * p + s[i] - 'a' + 1) % mod;
    for (i = 0; i < l1; ++i)
        h1 = (h1 * p + beg[i] - 'a' + 1) % mod;
    for (i = 0; i < l2; ++i)
        h2 = (h2 * p + en[i] - 'a' + 1) % mod;
    deg[0] = 1;
    for (int i = 0; i < n; ++i)
        deg[i + 1] = deg[i] * p % mod;
    int d = max(0, l1 - l2);
    for (int j, i = 0; i <= n - l1; ++i)
        for (j = i + d; j <= n - l2; ++j)
            if ((h[i + l1] - deg[l1] * h[i] + mod * mod) % mod == h1 && (h[j + l2] - deg[l2] * h[j] + mod * mod) % mod == h2)
                res[j - i].insert((h[j + l2] - deg[j + l2 - i] * h[i] + mod * mod) % mod);

    int ans = 0;
    for (int i = 0; i <= n; ++i)
        ans += (int)res[i].size();
    cout << ans;
    return 0;
}