#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr lint MOD = 10000000000007;
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
    int T;
    cin >> T;
    REP(t, T) {
        lint n;
        cin >> n;
        vector<lint> a(n);
        REP(i, n) cin >> a[i];
        lint diffmax = 0;
        FOR(i, 1, n) {
            diffmax = max(diffmax, a[i-1]-a[i]);
            a[i] = max(a[i], a[i-1]);
        }
        if(diffmax == 0) {
            cout << 0 << "\n";
            continue;
        }
        lint k = 1;
        while(true) {
            if(diffmax <= power(2, k, MOD)-1) {
                break;
            }
            k++;
        }
        cout << k << "\n";
    }
}