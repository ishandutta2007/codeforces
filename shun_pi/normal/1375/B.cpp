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
void yes(bool expr) {
  cout << (expr ? "YES" : "NO") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> a(n, vector<int>(m));
      REP(i, n) REP(j, m) cin >> a[i][j];
      bool flg = true;
      REP(i, n) REP(j, m) {
        if((i == 0 || i == n-1) && (j == 0 || j == m-1)) {
          if(a[i][j] > 2) flg = false;
          a[i][j] = 2;
        } else if((i == 0 || i == n-1) || (j == 0 || j == m-1)) {
          if(a[i][j] > 3) flg = false;
          a[i][j] = 3;
        } else {
          if(a[i][j] > 4) flg = false;
          a[i][j] = 4;
        }
      }
      yes(flg);
      if(flg) {
        REP(i, n) {
          REP(j, m) cout << a[i][j] << (j!=m-1 ? " " : "");
          cout << "\n";
        }
      }
    }
}