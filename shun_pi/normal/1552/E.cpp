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
  int n, k;
  cin >> n >> k;
  vector<int> c(n*k);
  REP(i, n*k) cin >> c[i];
  REP(i, n*k) c[i]--;
  int lim = (n-1)/(k-1) + 1;
  vector<P> ans(n);
  vector<bool> done(n);
  REP(z, lim) {
    set<P> st;
    REP(i, n*k) if(!done[c[i]]) {
      auto itr = st.upper_bound(P(c[i], -1));
      if(itr != st.end() && (*itr).first == c[i]) {
        ans[c[i]] = P(min(i, (*itr).second), max(i, (*itr).second));
        done[c[i]] = true;
        st.clear();
      } else st.insert(P(c[i], i));
    }
  }
  REP(i, n) cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
}