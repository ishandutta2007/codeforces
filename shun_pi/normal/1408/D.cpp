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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  vector<P> cd(m);
  REP(i, n) cin >> a[i] >> b[i];
  REP(i, m) cin >> cd[i].first >> cd[i].second;
  sort(ALL(cd), [](auto const &a, auto const &b) { return a.second > b.second; });
  set<P> st;
  REP(i, n) {
    int lastx = -1;
    REP(j, m) {
      int y = cd[j].second - b[i];
      int x = cd[j].first - a[i];
      if(y < 0) break;
      if(x < lastx) continue;
      P tmp = P(x, y+1);
      auto itr = st.lower_bound(tmp);
      if(itr == st.end() || (*itr).second < y+1) {
        st.insert(tmp);
        auto itr = st.find(tmp);
        vector<P> remove;
        while(true) {
          if(itr == st.begin()) break;
          itr--;
          if((*itr).second < y+1) remove.push_back(*itr);
          else break;
        }
        for(P p : remove) st.erase(p);
      }
    }
  }
  int lastx = 0;
  int ans = 1e9;
  for(P p : st) {
    //cout << p.first << " " << p.second << endl;
    chmin(ans, lastx + p.second);
    lastx = p.first + 1;
  }
  chmin(ans, lastx);
  cout << ans << endl;
}