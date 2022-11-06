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
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    vector<vector<lint>> dp(n, vector<lint>(2));
    IREP(i, n-1) {
      dp[i][0] = dp[i+1][0] + abs(a[i] - a[i+1]); 
      dp[i][1] = dp[i+1][1] + abs(a[i] - a[i+1]);
      if(i < n-2) chmin(dp[i][1], dp[i+2][0] + abs(a[i] - a[i+2]));
      else dp[i][1] = 0;
    }
    cout << min(dp[0][0], min(dp[0][1], dp[1][0])) << "\n";
  }
}