#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
int maxbit(int x) {
  int ret = 0;
  while(x > 0) {
    x /= 2;
    ret++;
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  vector<int> maxbitcnt(31);
  REP(i, n) maxbitcnt[maxbit(a[i])]++;
  REP(i, 31) {
    if(maxbitcnt[i] >= 3) {
      cout << 1 << endl;
      return 0;
    }
  }
  int ans = 1e9;
  REP(i, n-1) {
    int val1 = 0;
    REP(j, n) {
      if(i-j < 0) break;
      val1 ^= a[i-j];
      int val2 = 0;
      REP(k, n) {
        if(i+1+k >= n) break;
        val2 ^= a[i+1+k];
        if(val1 > val2) {
          chmin(ans, j+k);
        }
      }
    }
  }
  if(ans == 1e9) cout << -1 << endl;
  else cout << ans << endl;
}