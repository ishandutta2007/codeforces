#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int64_t power(int64_t x, int64_t n, int64_t mod) {
  int64_t ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}
int main()
{
    lint n, m;
    cin >> n >> m;
    lint ans = 0;
    vector<lint> frac(250001);
    frac[0] = 1;
    FOR(i, 1, 250001) {
        frac[i] = frac[i-1] * i % m;
    }
    FOR(i, 1, n+1) {
        ans = (ans + (n-i+1) * (n-i+1) % m * frac[n-i] % m * frac[i] % m) % m;
    }
    cout << ans << endl;
}