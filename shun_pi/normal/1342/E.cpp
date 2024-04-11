#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 998244353;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
lint power(lint x, lint n, lint mod) {
  lint ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint n, k;
    cin >> n >> k;
    if(k >= n) {
        cout << 0 << endl;
        return 0;
    }
    vector<lint> frac(200001);
    frac[0] = 1;
    FOR(i, 1, 200001) {
        frac[i] = frac[i-1] * i % MOD;
    }
    if(k == 0) {
        cout << frac[n] << endl;
        return 0;
    }
    lint ans = 0;
    FOR(i, 1, n-k+1) {
        lint ele = frac[n-k] * power(frac[i], MOD-2, MOD) % MOD * power(frac[n-k-i], MOD-2, MOD) % MOD * power(i, n, MOD) % MOD;
        if(i%2 == (n-k)%2) {
            ans = (ans + ele) % MOD;
        } else {
            ans = (ans - ele + MOD) % MOD;
        }
    }
    ans = ans * 2 % MOD * frac[n] % MOD * power(frac[n-k], MOD-2, MOD) % MOD * power(frac[k], MOD-2, MOD) % MOD;
    cout << ans << endl;
}