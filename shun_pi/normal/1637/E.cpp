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
    map<lint, lint> mp;
    REP(i, n) mp[a[i]]++;
    map<lint, vector<lint>> x;
    for (auto const& [key, val] : mp) {
      if(x.find(val) == x.end()) x[val] = vector<lint>();
      x[val].push_back(key);
    }
    vector<lint> keylist;
    for (auto const& [key, val] : x) {
      keylist.push_back(key);
      sort(ALL(x[key]), greater<lint>());
    }
    set<PL> st;
    REP(i, m) {
      lint x, y;
      cin >> x >> y;
      st.insert(PL(x, y));
      st.insert(PL(y, x));
    }
    lint ans = 0;
    for (auto const& [key, val] : x) {
      REP(i, val.size()) {
        FOR(j, i+1, val.size()) {
          lint tmp = (lint)key * 2 * (val[i] + val[j]);
          if(tmp <= ans) break;
          if(st.find(PL(val[i], val[j])) == st.end()) ans = tmp;
        }
      }
    }
    REP(i, keylist.size()) FOR(j, i+1, keylist.size()) {
      REP(k, x[keylist[i]].size()) {
        REP(l, x[keylist[j]].size()) {
          lint tmp = (lint)(keylist[i] + keylist[j]) * (x[keylist[i]][k] + x[keylist[j]][l]);
          if(tmp <= ans) break;
          if(st.find(PL(x[keylist[i]][k], x[keylist[j]][l])) == st.end()) ans = tmp;
        }
      }
    }
    cout << ans << "\n";
  }
}