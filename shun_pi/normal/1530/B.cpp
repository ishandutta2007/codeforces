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
    int h, w;
    cin >> h >> w;
    int x = 0;
    int y = 0;
    int mode = 0;
    vector<string> ans(h);
    REP(i, h) REP(j, w) ans[i] += '0';
    vector<int> dx = {-1, -1, -1, 1, 1, 1, 0, 0};
    vector<int> dy = {-1, 0, 1, -1, 0, 1, 1, -1};
    while(true) {
      bool ok = true;
      REP(k, 8) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(ans[nx][ny] == '1') {
          ok = false;
          break;
        }
      }
      if(ok) ans[x][y] = '1';
      if(mode == 0) {
        x++;
        if(x == h-1) mode = 1;
      } else if(mode == 1) {
        y++;
        if(y == w-1) mode = 2;
      } else if(mode == 2) {
        x--;
        if(x == 0) mode = 3;
        
      } else {
        y--;
        if(y == 0) break;
      }
    }
    REP(i, h) cout << ans[i] << "\n";
  }
}