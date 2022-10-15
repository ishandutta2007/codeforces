#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
//#define inv(a) fpow(a, MOD-2)

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

ll n; int k;
int factorval[25];
int factorcnt[25];
int f[25][10005][60];
vector<ll> factors;

bool find_factor(void)
{
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            n /= i; factors.push_back(i); return true;
        }
    }
    return false;
}

int inv[105];

int main()
{
    cin >> n >> k;
    if (n == 1LL) {
        printf("1"); return 0;
    }
    while (find_factor());
    factors.push_back(n);
    sort(factors.begin(), factors.end());
    int nextfactor = 0;
    for (int i = 1; i <= 100; i++) inv[i] = fpow(i, MOD - 2);
    for (int i = 0; i < factors.size(); i++) {
        if (!i || factors[i] != factors[i-1]) {
            factorval[nextfactor] = factors[i] % MOD;
            factorcnt[nextfactor] = 1; nextfactor++;
        } else {
            factorcnt[nextfactor-1]++;
        }
    }
    int ans = 1;
    for (int i = 0; i < nextfactor; i++) {
        f[i][0][factorcnt[i]] = 1;
        for (int j = 1; j <= k; j++) {
            for (int a = 0; a <= factorcnt[i]; a++) {
                for (int b = a; b >= 0; b--) {
                    f[i][j][b] += mul(f[i][j-1][a], inv[a+1]);
                    if (f[i][j][b] >= MOD) f[i][j][b] -= MOD;
                }
            }
        }
        int total = 0;
        for (int j = 0; j <= factorcnt[i]; j++) {
            total += mul(f[i][k][j], fpow(factorval[i], j));
            if (total >= MOD) total -= MOD;
        }
        ans = mul(ans, total);
    }
    //cout << f[0][2][0] << ' ' << f[0][2][1] << endl;
    cout << ans;
    return 0;
}