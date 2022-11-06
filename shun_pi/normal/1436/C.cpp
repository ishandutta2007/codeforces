#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 10000;
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
  lint n, x, pos;
  cin >> n >> x >> pos;
  lint l = 0;
  lint r = n;
  lint xup = 0;
  lint xdown = 0;
  lint rest = n-1;
  while(l < r) {
    lint m = (l+r) / 2;
    if(m > pos) {
      r = m;
      xup++;
      rest--;
    } else if(m < pos) {
      l = m + 1;
      xdown++;
      rest--;
    } else {
      l = m + 1;
    }
  }
  lint ans = 1;
  REP(i, xup) ans = ans * (n-x-i) % MOD;
  REP(i, xdown) ans = ans * (x-1-i) % MOD;
  REP(i, rest) ans = ans * (rest-i) % MOD;
  cout << ans << endl;
}