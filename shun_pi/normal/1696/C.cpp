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
    int n, m;
    cin >> n >> m;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    int k;
    cin >> k;
    vector<lint> b(k);
    REP(i, k) cin >> b[i];
    lint asum = 0, bsum = 0;
    REP(i, n) asum += a[i];
    REP(i, k) bsum += b[i];
    if(asum != bsum) {
      cout << "No" << "\n";
      continue;
    }
    asum = 0, bsum = 0;
    lint ap = 0, bp = 0;
    lint an = 0, bn = 0, ac = 0, bc = 0;
    bool ok = true;
    while(ap < n && bp < k) {
      if(ac == 0) {
        an = a[ap];
        ac = 1;
        while(an%m == 0) {
          an /= m;
          ac *= m;
        }
      }
      if(bc == 0) {
        bn = b[bp];
        bc = 1;
        while(bn%m == 0) {
          bn /= m;
          bc *= m;
        }
      }
      if(an != bn) ok = false;
      lint d = min(ac, bc);
      ac -= d;
      bc -= d;
      if(ac == 0) ap++;
      if(bc == 0) bp++;
    }
    yes(ok);
  }
}