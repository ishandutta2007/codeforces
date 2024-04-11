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
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector<int> top(10, n);
    vector<int> bot(10);
    vector<int> left(10, n);
    vector<int> right(10);
    REP(i, n) REP(j, n) {
      chmin(top[s[i][j]-'0'], i);
      chmax(bot[s[i][j]-'0'], i);
      chmin(left[s[i][j]-'0'], j);
      chmax(right[s[i][j]-'0'], j);
    }
    vector<int> ans(10);
    REP(d, 10) {
      REP(i, n) {
        int l = n;
        int r = 0;
        REP(j, n) {
          if(s[i][j]-'0' == d) {
            chmin(l, j);
            chmax(r, j);
            chmax(ans[d], max(j, n-1-j)*(i-top[d]));
            chmax(ans[d], max(j, n-1-j)*(bot[d]-i));
          }
        }
        chmax(ans[d], (r-l)*max(i, n-1-i));
      }
      REP(j, n) {
        int t = n;
        int b = 0;
        REP(i, n) {
          if(s[i][j]-'0' == d) {
            chmin(t, i);
            chmax(b, i);
            chmax(ans[d], max(i, n-1-i)*(j-left[d]));
            chmax(ans[d], max(i, n-1-i)*(right[d]-j));
          }
        }
        chmax(ans[d], (b-t)*max(j, n-1-j));
      }
    }
    REP(i, 10) cout << ans[i] << (i!=10-1 ? " " : "");
    cout << "\n";
  }
}