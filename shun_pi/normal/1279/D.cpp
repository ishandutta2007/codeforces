#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr lint MOD = 998244353;
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
    lint n;
    cin >> n;
    vector<vector<lint>> item;
    lint item_max = 0;
    REP(i, n) {
        item.emplace_back();
        lint m;
        cin >> m;
        REP(j, m) {
            lint k;
            cin >> k;
            item[i].push_back(k);
            if(k > item_max) item_max = k;
        }
    }
    vector<lint> item_num(item_max+1);
    REP(i, n) {
        REP(j, item[i].size()) {
            item_num[item[i][j]]++;
        }
    }
    lint ans = 0;
    REP(i, n) {
        REP(j, item[i].size()) {
            ans = (ans + (power(n, MOD-2, MOD) * power((lint)item[i].size(), MOD-2, MOD) % MOD * item_num[item[i][j]] % MOD * power(n, MOD-2, MOD) % MOD) ) % MOD;
        }
    }
    cout << ans << endl;
}