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
    lint l, r;
    cin >> l >> r;
    l--;
    lint ll = 0;
    lint rr = 1e9 + 1;
    while(rr - ll > 1) {
      lint m = (ll + rr) / 2;
      if(m * m > l) rr = m;
      else ll = m;
    } 
    lint ls = rr - 1;
    ll = 0;
    rr = 1e9 + 1;
    while(rr - ll > 1) {
      lint m = (ll + rr) / 2;
      if(m * m > r) rr = m;
      else ll = m;
    } 
    lint rs = rr - 1;
    lint ans = (rs - ls) * 3;
    REP(i, 3) {
      if(l >= ls*(ls+i)) ans--;
      if(r >= rs*(rs+i)) ans++;
    }
    cout << ans << "\n";
  }
}