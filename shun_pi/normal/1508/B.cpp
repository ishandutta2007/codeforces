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
    lint n, k;
    cin >> n >> k;
    k--;
    vector<lint> dp(n);
    dp[n-1] = 1;
    lint S = 1;
    IREP(i, n-1) {
      dp[i] = S + 1;
      S += dp[i];
      if(S > 2e18) break;
    }
    REP(i, n) dp[i]--;
    vector<int> ans(n);
    REP(i, n) ans[i] = i+1;
    int last = n-1;
    bool mode = false;
    REP(i, n) {
      //cout << i << " " << k << endl;
      if(dp[i] < 0) {
        continue;
      }
      if(mode && k <= dp[i] && k > dp[i+1]) {
        int ptr1 = last;
        int ptr2 = i;
        while(ptr1 < ptr2) {
          swap(ans[ptr1], ans[ptr2]);
          ptr1++;
          ptr2--;
        }
        mode = false;
        k = dp[i] - k;
      } else if(dp[i] == k) {
        int ptr1 = i;
        int ptr2 = n-1;
        while(ptr1 < ptr2) {
          swap(ans[ptr1], ans[ptr2]);
          ptr1++;
          ptr2--;
        }
        k = 0;
        break;
      } else if(k <= dp[i] && k > dp[i+1]) {
        k = dp[i] - k;
        mode = true;
        last = i;
      }
    }
    if(k > 0) {
      cout << -1 << "\n";
      continue;
    }
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}