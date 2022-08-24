#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 1000100;
const ll P = 1000000087;

string A, L, R;
int N, lo, hi;

int n0[MAXN];
ll ps[MAXN];
ll dp[MAXN];
int z[MAXN][10]; // substr i and add j

ll pp[MAXN];
ll ahash[MAXN], lhash[MAXN], rhash[MAXN];

ll get_v (ll* h, int start, int len)
{
    if (start)
        return (((h[start+len] - h[start] * pp[len]) % P) + P) % P;
    return h[len];
}

bool lwin (int c)
{
    if (get_v (ahash, c, lo) == get_v (lhash, 0, lo))
        return true;
    int rlo = 0, rhi = lo - 1;
    while (rlo < rhi)
    {
        int mid = (rlo + rhi + 1) / 2;
        if (get_v (ahash, c, mid) == get_v (lhash, 0, mid))
            rlo = mid;
        else
            rhi = mid - 1;
    }
    return L[rlo] < A[c+rlo];
}

bool hwin (int c)
{
    if (get_v (ahash, c, hi) == get_v (rhash, 0, hi))
        return true;
    int rlo = 0, rhi = hi - 1;
    while (rlo < rhi)
    {
        int mid = (rlo + rhi + 1) / 2;
        if (get_v (ahash, c, mid) == get_v (rhash, 0, mid))
            rlo = mid;
        else
            rhi = mid - 1;
    }
    return R[rlo] > A[c+rlo];
}

void compute (int cloc)
{
    if (cloc < N && A[cloc] == '0' && (L[0] != '0'))
        return;
    if (cloc < lo)
        return;

    ll sstart = cloc - hi + 1, send = cloc - lo;
    ll res = ps[send] - ps[max(sstart, 0LL)];
    if (cloc >= hi && hwin (cloc-hi))
        res += dp[cloc-hi];
    if (lwin (cloc-lo))
        res += dp[cloc-lo];

    dp[n0[cloc]] = (dp[n0[cloc]] + res + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> A >> L >> R;
    N = A.length();
    lo = L.length();
    hi = R.length();

    pp[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pp[i] = (pp[i-1] * MOD) % P;
    for (int i = 0; i < N; i++)
        ahash[i+1] = (ahash[i] * MOD + A[i]) % P;
    for (int i = 0; i < lo; i++)
        lhash[i+1] = (lhash[i] * MOD + L[i]) % P;
    for (int i = 0; i < hi; i++)
        rhash[i+1] = (rhash[i] * MOD + R[i]) % P;

    n0[N] = N;
    for (int i = N - 1; i >= 0; i--)
    {
        n0[i] = n0[i+1];
        if (A[i] != '0')
            n0[i] = i;
    }

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        ps[i] = (ps[i-1] + dp[i-1]) % MOD;
        compute (i);
        //cout << dp[i] << "\n";
    }
    cout << dp[N] << "\n";
}