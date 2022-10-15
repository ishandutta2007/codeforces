#include <cstdio>
#include <algorithm>
#include <vector>
//
using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int siz;
int rev[1050000];
int n;

void prentt(int s)
{
    siz = 1;
    while (siz < s * 2) siz <<= 1;
    for (int i = 0; i < siz; i++) {
        rev[i] = (i & 1 ? rev[i - 1] | (siz >> 1) : rev[i >> 1] >> 1);
    }
}

void ntt(int* poly, bool inv)
{
    for (int i = 0; i < siz; i++) {
        if (i < rev[i]) {
            int t = poly[i]; poly[i] = poly[rev[i]]; poly[rev[i]] = t;
        }
    }
    for (int csiz = 2; csiz <= siz; csiz <<= 1) {
        int root = fpow(3, (MOD - 1) / csiz);
        if (inv) root = fpow(root, MOD - 2);
        for (int st = 0; st < siz; st += csiz) {
            int curr = 1;
            for (int cur = st; cur < st + (csiz >> 1); cur++) {
                int tmp = mul(curr, poly[cur + (csiz >> 1)]);
                poly[cur + (csiz >> 1)] = poly[cur] - tmp + MOD;
                if (poly[cur + (csiz >> 1)] >= MOD) poly[cur + (csiz >> 1)] -= MOD;
                poly[cur] = poly[cur] + tmp;
                if (poly[cur] >= MOD) poly[cur] -= MOD;
                curr = mul(curr, root);
            }
        }
    }
    if (inv) {
        int invs = fpow(siz, MOD - 2);
        for (int i = 0; i < siz; i++) poly[i] = mul(poly[i], invs);
    }
}

int a[1050000];
int b[1050000];
int a2[1050000];
int b2[1050000];
int a3[1050000];
int b3[1050000];
int ans[1050000];
char s[1050000];

void work(void)
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == 'V' ? 1 : (s[i] == 'K' ? 2 : 0));
        b[n-i-1] = a[i];
    }
    for (int i = 0; i < n; i++) {
        a2[i] = mul(a[i], a[i]);
        a3[i] = mul(a2[i], a[i]);
        b2[i] = mul(b[i], b[i]);
        b3[i] = mul(b2[i], b[i]);
    }
    prentt(n);
    ntt(a, false);
    ntt(b, false);
    ntt(a2, false);
    ntt(b2, false);
    ntt(a3, false);
    ntt(b3, false);
    for (int i = 0; i < siz; i++) {
        ll ansv = (ll)a3[i] * (ll)b[i] - 2LL * (ll)a2[i] * (ll)b2[i]
            + (ll)a[i] * (ll)b3[i];
        ans[i] = ((ansv % MOD) + MOD) % MOD;
    }
    ntt(ans, true);
    vector<int> output;
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = i; j <= n; j += i) {
            if (j != n && ans[n - j - 1]) good = false;
        }
        if (good) output.push_back(i);
    }
    printf("%d\n", (int)output.size());
    for (int i = 0; i < output.size(); i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
    for (int i = 0; i < siz; i++) {
        a[i] = b[i] = a2[i] = b2[i] = a3[i] = b3[i] = 0;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        work();
    }
    return 0;
}