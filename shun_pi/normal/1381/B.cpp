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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "YES" : "NO") << "\n";}
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
    vector<int> p(2*n);
    REP(i, 2*n) cin >> p[i];
    vector<int> block;
    int first = p[0];
    int cnt = 1;
    FOR(i, 1, 2*n) {
      if(p[i] > first) {
        block.push_back(cnt);
        first = p[i];
        cnt = 1;  
      } else cnt++;
    }
    vector<bool> dp(n+1);
    dp[0] = true;
    REP(i, block.size()) {
      IREP(j, n+1) if(j-block[i] >= 0 && dp[j-block[i]]) dp[j] = true; 
    }
    yes(dp[n]);
  }
}