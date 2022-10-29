#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

typedef vector< vector< int > > mt;

vector< mt > dp;
mt tmp;
mt base;

mt
shift(const mt &a, int shift)
{
    int k = int(a.size()) - 1;
    // left shift instead of right
    shift = (k - shift) % k;
    mt res = a;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            res[i][j] = a[(i + shift) % k][(j + shift) % k];
        }
    }
    for (int j = 0; j < k; ++j) {
        res[k][j] = a[k][(j + shift) % k];
    }
    return res;
}

mt
operator *(const mt &a, const mt &b)
{
    static int aa[200][200], bb[200][200];
    int n = int(a.size()), k = int(a[0].size()), m = int(b[0].size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            aa[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            bb[j][i] = b[i][j];
        }
    }
    mt res(n, vector< int >(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp = 0;
            for (int l = 0; l < k; ++l) {
                tmp = (tmp + 1ll * aa[i][l] * bb[j][l]) % MOD;
            }
            res[i][j] = tmp;
        }
    }
    return res;
}

int
main()
{
    ll n;
    int k;
    cin >> n >> k;
    int max_depth = 0;
    {
        ll tmp = n;
        while (tmp != 0) {
            ++max_depth;
            tmp /= k;
        }
    }
    dp.resize(max_depth);
    // constructing matrices for dynamic programming
    { // matrices for initial level
        dp[0].assign(k + 1, vector< int >(k + 1, 0));
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[0][i][j] = (i == j || j == 0);
            }
        }
        mt e(k + 1, vector< int >(k + 1, 0));
        for (int i = 0; i <= k; ++i) {
            e[i][i] = 1;
        }
        for (int depth = 1; depth < max_depth; ++depth) {
            dp[depth] = e;
            mt bs = dp[depth - 1];
            int curx = k;
            for (int i = 0; (1 << i) <= curx; ++i) {
                if (curx & (1 << i)) {
                    dp[depth] = bs * shift(dp[depth], (1 << i));
                    curx ^= (1 << i);
                }
                bs = bs * shift(bs, (1 << i));
            }
        }
    }
    base.assign(1, vector< int >(k + 1, 0));
    base[0][k] = 1;
    int sl = 0;
    ll x = n;
    vector< int > vec;
    while (x != 0) {
        vec.push_back(x % k);
        x /= k;
    }
    int len = int(vec.size());
    for (int cur_depth = len - 1; cur_depth >= 0; --cur_depth) {
        int rest = vec[cur_depth];
        for (int it = 0; it < rest; ++it, sl = (sl + 1) % k) {
            base = base * shift(dp[cur_depth], sl);
        }
    }
    {
        int res = 0;
        for (int i = 0; i <= k; ++i) {
            res = (res + base[0][i]) % MOD;
        }
        cout << res << '\n';
    }
    return 0;
}