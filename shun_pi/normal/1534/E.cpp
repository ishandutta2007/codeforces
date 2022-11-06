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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
  dp[0][0] = 0;
  REP(i, n) REP(j, n+1) {
    if(dp[i][j] == -1) continue;
    REP(odd, k+1) {
      int even = k - odd;
      if(odd > j || even > n-j) continue;
      int x = j - odd + even;
      if(x < 0 || x > n) continue;
      dp[i+1][x] = j;
    }
  }
  int d = -1;
  REP(i, n+1) if(dp[i][n] != -1) {
    d = i;
    break;
  }
  if(d == -1) {
    cout << -1 << "\n";
    return 0;
  }
  vector<int> odd_num;
  int col = n;
  IFOR(i, 1, d+1) {
    odd_num.push_back((col - dp[i][col] + k) / 2);
    col = dp[i][col];
  }
  int ans = 0;
  col = 0;
  set<int> even;
  REP(i, n) even.insert(i);
  set<int> odd;
  IREP(i, d) {
    vector<int> que;
    vector<int> ote;
    REP(j, odd_num[i]) {
      que.push_back(*even.begin());
      ote.push_back(*even.begin());
      even.erase(even.begin());
    }
    REP(j, k-odd_num[i]) {
      que.push_back(*odd.begin());
      even.insert(*odd.begin());
      odd.erase(odd.begin());
    }
    for(int x : ote) odd.insert(x);
    cout << "? ";
    REP(i, k) cout << que[i]+1 << (i!=k-1 ? " " : "");
    cout << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    ans ^= ret;
  }
  cout << "! " << ans << "\n";
  cout.flush();
}