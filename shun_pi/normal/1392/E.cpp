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
  int n;
  cin >> n;
  vector<vector<lint>> a(n, vector<lint>(n));
  int x = 1;
  int y = 0;
  lint num = 1;
  while(y != n-1) {
    int xt = x;
    int yt = y;
    bool mode = false;
    while(xt >= 0 && yt < n) {
      if(mode) a[yt][xt] = num;
      xt--; yt++; mode = !mode;
    }
    if(x == n-1) y++;
    else x++;
    num *= 2;
  }
  REP(i, n) {
    REP(j, n) cout << a[i][j] << (j!=n-1 ? " " : "");
    cout << "\n";
    cout.flush();
  }
  int Q;
  cin >> Q;
  while(Q--) {
    lint k;
    cin >> k;
    int xt = 0;
    int yt = 0;
    lint bit = 0;
    vector<P> ans;
    while(true) {
      ans.push_back(P(xt+1, yt+1));
      if(xt == n-1 && yt == n-1) break;
      if(xt == n-1) yt++;
      else if(yt == n-1) xt++;
      else {
        if((k>>bit)&1) {
          if(a[xt+1][yt] > 0) xt++;
          else yt++;
        } else {
          if(a[xt+1][yt] == 0) xt++;
          else yt++;
        }
      }
      bit++;
    }
    REP(i, ans.size()) {
      cout << ans[i].first << " " << ans[i].second << "\n";
      cout.flush();
    }
  }
}