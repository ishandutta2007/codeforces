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
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int ans = 0;
    REP(x, z+1) {
      int sum = 0;
      if(k+1-2*x <= 0) continue;
      REP(i, k+1-2*x) sum += a[i];
      int max2 = 0;
      REP(i, k+1-2*x) max2 = max(max2, a[i] + a[i+1]);
      ans = max(ans, sum + x*max2);
    }
    cout << ans << "\n";
  }
}