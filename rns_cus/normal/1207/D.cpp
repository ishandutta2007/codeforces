#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, fac[N];
const int mod = 998244353;

typedef pair <int, int> pii;
pii p[N];
map <int, int> A, B;
map <pii, int> mp;

int main() {
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    for (int i = 1, a, b; i <= n; i ++) scanf("%d %d", &a, &b), A[a] ++, B[b] ++, mp[pii(a,b)] ++, p[i] = pii(a, b);
    int rlt = fac[n], c;
    c = 1;
    for (auto p : A) c = 1ll * c * fac[p.second] % mod;
    rlt -= c; if (rlt < 0) rlt += mod;
    c = 1;
    for (auto p : B) c = 1ll * c * fac[p.second] % mod;
    rlt -= c; if (rlt < 0) rlt += mod;
    c = 1;
    sort(p + 1, p + n + 1);
    for (int i = 1; i < n; i ++) if (p[i].second > p[i+1].second) c = 0;
    for (auto p : mp) c = 1ll * c * fac[p.second] % mod;
    rlt += c; if (rlt >= mod) rlt -= mod;
    printf("%d\n", rlt);

    return 0;
}