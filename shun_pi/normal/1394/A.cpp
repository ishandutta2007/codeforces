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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint d, n, m;
  cin >> n >> d >> m;
  vector<lint> a(n);
  REP(i, n) cin >> a[i];
  vector<lint> up;
  vector<lint> down;
  REP(i, n) if(a[i] > m) {
    up.push_back(a[i]);
  } else {
    down.push_back(a[i]);
  }
  sort(ALL(up), greater<lint>());
  while(down.size() < n) down.push_back(0);
  sort(ALL(down));
  lint sum = 0;
  REP(i, n) sum += down[i];
  lint ans = sum;
  int upidx = 0;
  int downidx = 0;
  while(true) {
    if(upidx == up.size()) break;
    sum += up[upidx];
    upidx++;
    bool flg = false;
    if(upidx != 1) {
      REP(i, d+1) {
        if(downidx == down.size()) {
          flg = true;
          break;
        }
        sum -= down[downidx];
        downidx++;
      }
      if(flg) break;
    } else {
      REP(i, 1) {
        if(downidx == down.size()) {
          flg = true;
          break;
        }
        sum -= down[downidx];
        downidx++;
      }
      if(flg) break;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
}