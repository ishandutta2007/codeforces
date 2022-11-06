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
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> b(n);
    REP(i, n) cin >> b[i];
    vector<int> c(n);
    REP(i, n) cin >> c[i];
    vector<int> p(n);
    int last = 0;
    REP(i, n-1) {
      if(a[i] != last) {
        p[i] = a[i];
      } else if(b[i] != last) {
        p[i] = b[i];
      } else {
        p[i] = c[i];
      }
      last = p[i];
    }
    if(a[n-1] != last && a[n-1] != p[0]) {
      p[n-1] = a[n-1];
    } else if(b[n-1] != last && b[n-1] != p[0]) {
      p[n-1] = b[n-1];
    } else {
      p[n-1] = c[n-1];
    }
    REP(i, n) cout << p[i] << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}