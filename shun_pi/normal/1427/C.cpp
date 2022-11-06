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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int r, n;
  cin >> r >> n;
  vector<int> t(n+1), x(n+1), y(n+1);
  t[0] = 0; x[0] = 1; y[0] = 1;
  FOR(i, 1, n+1) cin >> t[i] >> x[i] >> y[i];
  vector<int> dp(n+1);
  vector<int> ma(n+1);
  dp[n] = 0;
  ma[n] = 0;
  IREP(i, n) {
    int tmp = -1;
    FOR(j, i+1, n+1) {
      if(t[j] - t[i] >= 1000) {
        chmax(tmp, ma[j]);
        break;
      }
      if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= t[j]-t[i]) chmax(tmp, dp[j]);
    }
    dp[i] = tmp + 1;
    ma[i] = max(dp[i], ma[i+1]);
  }
  cout << dp[0] << endl;
}