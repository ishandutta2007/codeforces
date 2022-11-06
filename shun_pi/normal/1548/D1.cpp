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
int gcd(int a, int b) {
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<P> xy(n);
  REP(i, n) cin >> xy[i].first >> xy[i].second;
  //REP(i, n) xy[i] = P(2*i, 2*i+2);
  vector<bitset<6000>> b(n);
  REP(i, n) FOR(j, i+1, n) {
    int g = gcd(abs(xy[i].first - xy[j].first), abs(xy[i].second - xy[j].second));
    if(g/2 % 2 == 1) {
      b[i].set(j);
      b[j].set(i);
    }
  }
  lint ans = 0;
  REP(i, n) FOR(j, i+1, n) {
    int tmp1 = b[i][j];
    int tmp2 = b[j][i];
    b[i].reset(j);
    b[j].reset(i);
    int tmp = (b[i] ^ b[j]).count();
    if(tmp1) ans += tmp;
    else ans += n - 2 - tmp;
    if(tmp1 == 1) b[i].set(j);
    if(tmp2 == 1) b[j].set(i);
  }
  cout << ans / 3 << endl;
}