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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i] >> b[i];
  vector<vector<vector<double>>> dp(n+1);
  REP(i, n+1) dp[i] = vector<vector<double>>(i+1, vector<double>(10001, -1));
  dp[0][0][0] = 0;
  REP(i, n) {
    REP(j, i+1) REP(k, 10001) {
      if(dp[i][j][k] < 0) continue;
      chmax(dp[i+1][j][k], dp[i][j][k] + (double)b[i] / 2.0);
      chmax(dp[i+1][j+1][k+a[i]], dp[i][j][k] + b[i]);
    }
  }
  vector<double> ans(n);
  REP(j, n) REP(k, 10001) {
    chmax(ans[j], min(dp[n][j+1][k], ((double)k)));
  }
  REP(i, n) cout << fixed << setprecision(10) << ans[i] << (i!=n-1 ? " " : "");
  cout << "\n";
}