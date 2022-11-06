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
    lint n, k;
    cin >> n >> k;
    lint l1 ,r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 > l2) {
      swap(l1, l2);
      swap(r1, r2);
    }
    lint onecnt = 0;
    lint zerocnt = 0;
    lint tmpk = 0;
    if(r1 > r2) {
      onecnt += l2 - l1;
      onecnt += r1 - r2;
      tmpk += (r2 - l2) * n;
    } else if(l2 < r1) {
      onecnt += l2 - l1;
      onecnt += r2 - r1;
      tmpk += (r1 - l2) * n;
    } else {
      onecnt += r2 - l1;
      zerocnt += l2 - r1;
    }
    if(tmpk >= k) {
      cout << 0 << "\n";
      continue;
    }
    lint ans = 1e18;
    lint tmpcnt = 0;
    REP(i, n) {
      if(tmpk >= k) break;
      if(k - tmpk <= onecnt) {
        ans = min(ans, tmpcnt + zerocnt + (k-tmpk));
        break;
      }
      tmpcnt += zerocnt + onecnt;
      tmpk += onecnt;
      ans = min(ans, tmpcnt + (k - tmpk) * 2);
    }
    cout << ans << "\n";
  }
}