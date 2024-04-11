#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
void yes(bool expr) {cout << (expr ? "Alice" : "Bob") << "\n";}
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
    int e = 0, o = 0;
    REP(i, n) {
      if(abs(a[i]) % 2 == 0) e++;
      else o++;
    }
    vector<vector<vector<vector<bool>>>> dp(e+1, vector<vector<vector<bool>>>(o+1, vector<vector<bool>>(2, vector<bool>(2))));
    dp[0][0][0][0] = true;
    dp[0][0][0][1] = true;
    FOR(i, 1, e+o+1) REP(j, i+1) {
      int ne = j;
      int no = i - j;
      if(ne > e || no > o) continue;
      REP(k, 2) REP(l, 2) {
        if(l == 0) {
          dp[ne][no][k][l] = false;
          if(ne > 0 && dp[ne-1][no][k][(l+1)%2]) dp[ne][no][k][l] = true;
          if(no > 0 && dp[ne][no-1][(k+1)%2][(l+1)%2]) dp[ne][no][k][l] = true;
        } else {
          dp[ne][no][k][l] = true;
          if(ne > 0 && !dp[ne-1][no][k][(l+1)%2]) dp[ne][no][k][l] = false;
          if(no > 0 && !dp[ne][no-1][k][(l+1)%2]) dp[ne][no][k][l] = false;
        }
      }
    }
    yes(dp[e][o][0][0]);
  }
}