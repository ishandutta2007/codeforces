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
void yes(bool expr) {cout << (expr ? "YES" : "NO") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  vector<lint> f = {1, 1};
  while(true) {
    lint n = f[f.size()-1] + f[f.size()-2];
    if(n > 1e11) break;
    f.push_back(n);
  }
  vector<lint> fs(f.size()-2);
  fs[0] = 1;
  FOR(i, 1, f.size()-2) fs[i] = fs[i-1] + f[i];

  while(T--) {
    int k;
    cin >> k;
    vector<lint> c(k);
    REP(i, k) cin >> c[i];
    sort(ALL(c));
    lint sum = 0;
    REP(i, k) sum += c[i];
    int n = -1;
    REP(i, fs.size()) if(fs[i] == sum) n = i+1;
    if(n == -1) {
      cout << "NO" << "\n";
      continue;
    }
    set<PL, greater<PL>> st;
    REP(i, k) st.insert(PL(c[i], i));
    bool ok = true;
    int last = -1;
    IREP(i, n) {
      PL pl = *st.begin();
      st.erase(pl);
      if(pl.first < f[i]) ok = false;
      if(last == pl.second) {
        if(i > 0) {
          PL pl2 = *st.begin();
          st.erase(pl2);
          if(pl2.first >= f[i]) {
            if(pl2.first - f[i] > 0) st.insert(PL(pl2.first - f[i], pl2.second));
            st.insert(pl);
            last = pl2.second;
            continue;
          }
        }
      } else {
        if(pl.first - f[i] > 0) st.insert(PL(pl.first-  f[i], pl.second));
        last = pl.second;
        continue;
      }
      ok = false;
    }
    
    yes(ok);
  }
}