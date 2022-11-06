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
lint power(lint x, lint n, lint mod) {
  lint ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    lint n, m, k;
    cin >> n >> m >> k;
    vector<unordered_set<int>> nbr(n);
    REP(i, m) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      nbr[u].insert(v);
      nbr[v].insert(u);
    }
    if(k*(k-1)/2 > m) {
      cout << -1 << "\n";
      continue;
    }
    set<P> st;
    REP(i, n) st.insert(P(nbr[i].size(), i));
    bool ok = false;
    while(st.size() >= k) {
      P p = *st.begin();
      if(p.first >= k) {
        ok = true;
        cout << "1 " << st.size() << "\n";
        vector<int> ans;
        for(P pp : st) ans.push_back(pp.second+1);
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << "\n";
        break;
      } else if(p.first == k-1) {
        bool ok2 = true;
        for(int x : nbr[p.second]) {
          if(nbr[x].find(p.second) == nbr[x].end()) {
            ok2 = false;
            break;
          }
          for(int y : nbr[p.second]) {
            if(y == x) continue;
            if(nbr[x].find(y) == nbr[x].end()) {
              ok2 = false;
              break;
            }
          }
          if(!ok2) break;
        }
        if(ok2) {
          cout << "2" << "\n";
          vector<int> ans;
          ans.push_back(p.second);
          for(int x : nbr[p.second]) ans.push_back(x);
          REP(i, ans.size()) cout << (ans[i]+1) << (i!=ans.size()-1 ? " " : "");
          cout << "\n";
          ok = true;
          break;
        }
      }
      for(int x : nbr[p.second]) {
        P pp = *st.find(P(nbr[x].size(), x));
        nbr[x].erase(p.second);
        st.erase(pp);
        P pp2 = P(pp.first-1, pp.second);
        st.insert(pp2);
      }
      st.erase(p);
    }
    if(ok) continue;
    cout << -1 << "\n";
  }
}