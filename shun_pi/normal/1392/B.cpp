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
  int T;
  cin >> T;
  while(T--) {
    lint n, k;
    cin >> n >> k;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    lint ma = -1e10;
    REP(i, n) ma = max(ma, a[i]);
    REP(i, n) a[i] = ma - a[i];
    if(k%2 == 0) {
      ma = -1e10;
      REP(i, n) ma = max(ma, a[i]);
      REP(i, n) a[i] = ma - a[i];
    }
    REP(i, n) cout << a[i] << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}