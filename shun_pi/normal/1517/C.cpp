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
  int n;
  cin >> n;
  vector<int> p(n);
  REP(i, n) cin >> p[i];
  vector<vector<int>> board(n, vector<int>(n));
  REP(i, n) board[i][i] = p[i];
  REP(i, n) {
    int rest = p[i] - 1;
    int x = i;
    int y = i;
    while(rest > 0) {
      if(y > 0 && board[x][y-1] == 0) y--;
      else x++;
      board[x][y] = p[i];
      rest--;
    }
  }
  REP(i, n) {
    REP(j, i+1) cout << board[i][j] << (j!=i+1-1 ? " " : "");
    cout << "\n";
  }
}