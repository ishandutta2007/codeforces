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
  lint n, C;
  cin >> n >> C;
  lint maxhd = 0;
  vector<lint> hd(C+1);
  REP(i, n) {
    lint c, d, h;
    cin >> c >> d >> h;
    chmax(hd[c], d*h);
  }
  lint m;
  cin >> m;
  vector<PL> mon(m);
  REP(i, m) {
    lint D, H;
    cin >> D >> H;
    mon[i] = PL(D*H, i);
  }
  sort(ALL(mon));
  vector<vector<lint>> rem(C+1);
  for(int i=1; i<=C; i++) for(int j=i; j<=C; j+=i) rem[j].push_back(i);
  vector<lint> nowhd(C+1);
  vector<lint> ans(m);
  lint cur = 0;
  lint ma = 0;
  REP(i, m) {
    while(ma <= mon[i].first && cur <= C) {
      cur++;
      if(cur > C) break;
      for(int x : rem[cur]) {
        nowhd[x] += hd[x];
        chmax(ma, nowhd[x]);
      }
    }
    if(cur == C+1) ans[mon[i].second] = -1;
    else ans[mon[i].second] = cur;
  }
  REP(i, m) cout << ans[i] << (i!=m-1 ? " " : "");
  cout << "\n";

}