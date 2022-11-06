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
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    l--; r--;
    int m = r - l + 1;
    vector<int> ans(n);
    FOR(i, l, r+1) ans[i] = i+1-l;
    int sum = m * (m+1) / 2;
    bool ok = false;
    IFOR(i, l, r+1) {
      while(true) {
        if(sum == s) {
          ok = true;
          break;
        }
        if(ans[i] == n-(r-i)) break;
        ans[i]++;
        sum++;
      }
      if(ok) break;
    }
    if(!ok) {
      cout << -1 << "\n";
      continue;
    }
    set<int> st;
    FOR(i, 1, n+1) st.insert(i);
    REP(i, n) st.erase(ans[i]);
    REP(i, n) if(ans[i] == 0) {
      ans[i] = *st.begin();
      st.erase(st.begin());
    }
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}