#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr lint MOD = 998244353;
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
    
    lint n;
    cin >> n;
    vector<string> a(n);
    REP(i, n) cin >> a[i];
    lint ans = 0;
    vector<lint> c(11);
    REP(i, n) {
        c[a[i].length()]++;
    }
    REP(i, n) {
        REP(j, a[i].length()) {
            lint ch = (lint)a[i][a[i].length()-j-1] - (lint)'0';
            FOR(d, 1, 11) {
                if(d-1 >= j) {
                    ans = ((ch * power((lint)10, (lint)2 * j, MOD) % MOD * c[d] % MOD) + ans )% MOD;
                    ans = ((ch * power((lint)10, (lint)2 * j + 1, MOD) % MOD * c[d] % MOD) + ans)% MOD;   
                } else {
                    ans = ((ch * power((lint)10, (lint)2 * (d) + (j-d), MOD) % MOD * 2 * c[d] % MOD) + ans )% MOD;
                }
            }
        }
    }
    cout << ans << endl;
}