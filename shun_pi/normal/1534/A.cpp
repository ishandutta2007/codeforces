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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector<string> ans1(n), ans2(n);
    REP(i, n) REP(j, m) {
      if((i+j)%2 == 0) ans1[i] += 'R';
      else ans1[i] += 'W';
      if((i+j)%2 == 0) ans2[i] += 'W';
      else ans2[i] += 'R';
    }
    bool ok1 = true;
    bool ok2 = true;
    REP(i, n) REP(j, m) if(s[i][j] != '.') {
      if(ans1[i][j] != s[i][j]) ok1 = false;
      if(ans2[i][j] != s[i][j]) ok2 = false;
    }
    if(ok1) {
      cout << "YES" << "\n";
      REP(i, n) cout << ans1[i] << "\n";
    } else if(ok2) {
      cout << "YES" << "\n";
      REP(i, n) cout << ans2[i] << "\n";
    } else cout << "NO" << "\n";
  }
}