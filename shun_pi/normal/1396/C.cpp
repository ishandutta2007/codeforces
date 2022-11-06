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
  lint n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<lint> a(n);
  REP(i, n) cin >> a[i];
  vector<lint> r2t(n);
  REP(i, n) r2t[i] = min(r2, (a[i]+1)*r1);
  vector<lint> dp1(n);
  vector<lint> dp2(n);
  dp1[n-1] = min(a[n-1]*r1 + r3, r2t[n-1] + 2*d + r1);
  dp1[n-2] = a[n-2]*r1 + r3 + d + a[n-1]*r1 + r3;
  chmin(dp1[n-2], r2t[n-2] + d + a[n-1]*r1 + r3 + d + r1);
  chmin(dp1[n-2], a[n-2]*r1 + r3 + d + r2t[n-1] + 2*d + r1);
  chmin(dp1[n-2], r2t[n-2] + d + r2t[n-1] + d + r1 + d + r1);
  dp2[n-1] = min(a[n-1]*r1 + r3 + d, r2t[n-1] + 2*d + r1 + d);
  dp2[n-2] = a[n-2]*r1 + r3 + d + a[n-1]*r1 + r3 + 2*d;
  chmin(dp2[n-2], r2t[n-2] + d + a[n-1]*r1 + r3 + d + r1 + d);
  chmin(dp2[n-2], a[n-2]*r1 + r3 + d + r2t[n-1] + 2*d + r1 + 2*d);
  chmin(dp2[n-2], r2t[n-2] + d + r2t[n-1] + d + r1 + d + r1 + 2*d);
  IREP(i, n-2) {
    dp1[i] = min(a[i]*r1 + r3, r2t[i] + 2*d + r1) + d + dp1[i+1];
    chmin(dp1[i], r2t[i] + d + dp2[i+1] + r1);
    chmin(dp1[i], r2t[i] + d + r2t[i+1] + d + r1 + d + r1 + d + dp1[i+2]);
    dp2[i] = min(a[i]*r1 + r3, r2t[i] + 2*d + r1) + d + dp2[i+1] + d;
    chmin(dp2[i], r2t[i] + d + dp2[i+1] + r1 + d);
    chmin(dp2[i], r2t[i] + d + r2t[i+1] + d + r1 + d + r1 + d + dp2[i+2] + d);
  }
  cout << dp1[0] << endl;
}