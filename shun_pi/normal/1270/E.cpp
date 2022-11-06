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
    int n;
    cin >> n;
    vector<lint> x(n);
    vector<lint> y(n);
    REP(i, n) {
        cin >> x[i] >> y[i];
    }
    while(true) {
        vector<int> ans;
        REP(i, n) {
            if(abs(x[i] + y[i])%2 == 0) ans.push_back(i+1);
        }
        if(ans.size() != 0 && ans.size() != n) {
            cout << ans.size() << endl;
            REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
            cout << endl;
            return 0;
        } 
        if(ans.size() == 0) {
            REP(i, n) x[i]++;
        }
        REP(i, n) {
            int xt = x[i];
            int yt = y[i];
            x[i] = (xt - yt) / 2;
            y[i] = (xt + yt) / 2;
        }
    }
    
    
}