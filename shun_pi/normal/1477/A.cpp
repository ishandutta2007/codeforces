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
void yes(bool expr) {cout << (expr ? "YES" : "NO") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
lint gcd(lint a, lint b) {
  if(a < b) {
    swap(a, b);
  }
  while(b > 0) {
    lint r = a % b;
    a = b;
    b = r;
  }
  return a;
}
lint lcm(lint a, lint b) {
  return a * b / gcd(a, b);
}
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
    set<lint> x;
    REP(i, n) {
      lint y;
      cin >> y;
      x.insert(y);
    }
    lint g = 0;
    lint last = 0;
    bool first = false;
    for(lint a : x) {
      if(!first) {
        last = a;
        first = true;
      } else {
        if(g == 0) {
          g = a - last;
        } else {
          g = gcd(g, a-last);
        }
        last = a;
      }
    }
    bool ans = false;
    if(g != 0) {
      for(lint a : x) if((k+(lint)1e18)%g == (a+(lint)1e18)%g) ans = true;
    } else for(lint a : x) {
      if(k == a) ans = true;
    }
    yes(ans);
  }
}