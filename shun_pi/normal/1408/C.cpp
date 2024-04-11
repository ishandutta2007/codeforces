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
    lint n, L;
    cin >> n >> L;
    vector<lint> a(n+2);
    a[0] = 0;
    a[n+1] = L;
    REP(i, n) cin >> a[i+1];
    double l = 0.01;
    double r = L;
    while(r-l > 1e-7) {
      double m = (l+r) / 2;
      double ta = m;
      double xa = 0;
      double sa = 1;
      FOR(i, 1, n+2) {
        if((a[i] - xa)/sa > ta) {
          xa += sa * ta;
          ta = 0;
          break;
        } else {
          ta -= (a[i] - xa) / sa;
          xa = a[i];
          sa += 1;
        }
      }
      if(ta > 0) {
        r = m;
        continue;
      }
      double tb = m;
      double xb = L;
      double sb = 1;
      IREP(i, n+1) {
        if((xb - a[i])/sb > tb) {
          xb -= sb * tb;
          tb = 0;
          break;
        } else {
          tb -= (xb - a[i]) / sb;
          xb = a[i];
          sb += 1;
        }
      }
      if(tb > 0) {
        r = m;
        continue;
      }
      if(xb < xa) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << fixed << setprecision(10) << r << "\n";
  }
}