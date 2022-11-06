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
  vector<bool> prime(100001, true);
  prime[1] = false;
  FOR(i, 2, 100001) if(prime[i]) for(int j=i*2; j<100001; j+=i) prime[j] = false;
  while(T--) {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    REP(i, n) {
      ans[i][i] = 1;
      ans[i][(i+1)%n] = 1;
    }
    REP(i, n) {
      REP(j, n) cout << ans[i][j] << (j!=n-1 ? " " : "");
      cout << "\n";
    }
  }
}