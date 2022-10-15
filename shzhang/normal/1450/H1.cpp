#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n, m;
char s[200005];
int fact[200005];
int ifact[200005];

int C(int x, int y)
{
    return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

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

void cntdist(vector<int>& pos, int* ans)
{
    int start = 0, oddsp = 0, evensp = 0;
    for (int i = 0; i < pos.size(); i++) {
        char chr = s[pos[i]]; bool isodd = (i % 2 != 0);
        if (chr == '?') {
            if (isodd) oddsp++;
            else evensp++;
        } else if (chr == 'b') {
            if (isodd) start++;
            else start--;
        } else {
            if (isodd) start--;
            else start++;
        }
    }
    for (int x = 0; x <= oddsp + evensp; x++) {
        int val = start - oddsp - evensp + 2 * x;
        int valpos = val + pos.size();
        if (val < 0) val += MOD;
        ans[valpos] = C(oddsp + evensp, x);
    }
}

int pdist[400005];
int inv2[200005];

int question_marks = 0;

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) fact[i] = mul(i, fact[i-1]);
    ifact[200000] = fpow(fact[200000], MOD - 2);
    for (int i = 199999; i >= 0; i--) ifact[i] = mul(ifact[i+1], i+1);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') question_marks++;
    }
    vector<int> pos; for (int i = 1; i <= n; i++) pos.push_back(i);
    cntdist(pos, pdist);
    int ans = 0;
    for (int i = 0; i <= 2 * n; i++) {
        int absv = (i - n > 0 ? i - n : n - i);
        if ((absv + 1000000) % 4) continue;
        ans += mul(absv, pdist[i]);
        if (ans >= MOD) ans -= MOD;
    }
    inv2[0] = 1;
    int inv2val = fpow(2, MOD - 2);
    for (int i = 1; i <= n + 1; i++) inv2[i] = mul(inv2[i-1], inv2val);
    ans = mul(ans, inv2[question_marks + 1]);
    printf("%d", ans);
    return 0;
}