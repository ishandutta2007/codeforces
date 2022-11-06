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
  lint n;
  cin >> n;
  vector<lint> a(n);
  REP(i, n) cin >> a[i];
  if(n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
  } else {
    cout << 1 << " " << n-1 << endl;
    vector<lint> out(n-1);
    REP(i, n-1) {
      lint rem = (a[i] + 1000000000*n) % n;
      out[i] = rem * (n-1);
      a[i] += out[i];
    }
    REP(i, n-1) cout << out[i] << (i!=n-1-1 ? " " : "");
    cout << "\n";
  }
  cout << n << " " << n << endl;
  cout << -a[n-1] << endl;
  a[n-1] = 0;
  cout << 1 << " " << n << endl;
  vector<lint> out2(n);
  REP(i, n) out2[i] = -a[i];
  REP(i, n) cout << out2[i] << (i!=n-1 ? " " : "");
  cout << "\n";
}