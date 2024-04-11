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
  lint n, k;
  cin >> n >> k;
  vector<lint> ret(n);
  REP(i, n) {
    int x = i;
    int y = (i+1)%n;
    if(i == n-1 && n%2 == 0) y++; 
    cout << "or " << x+1 << " " << y+1 << "\n";
    cout.flush();
    lint o;
    cin >> o;
    cout << "and " << x+1 << " " << y+1 << "\n";
    cout.flush();
    lint a;
    cin >> a;
    ret[i] = a + o;
  }
  vector<lint> ans(n);
  lint tmp = 0;
  REP(i, n) {
    if(i%2 == 0) tmp += ret[i];
    else tmp -= ret[i];
  }
  if(n%2 != 0) {
    ans[0] = tmp / 2;
  } else {
    tmp += ret[0];
    ans[0] = tmp / 2;
  }
  FOR(i, 1, n) ans[i] = ret[i-1] - ans[i-1];
  sort(ALL(ans));
  //REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
  //cout << "\n";
  cout << "finish " << ans[k-1] << "\n";
  cout.flush();
}