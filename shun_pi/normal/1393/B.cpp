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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "YES" : "NO") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  vector<int> cnt(100000);
  REP(i, n) cnt[a[i]-1]++;
  multiset<int, greater<int>> st;
  REP(i, 100000) st.insert(cnt[i]);
  int q;
  cin >> q;
  while(q--) {
    char c;
    int x;
    cin >> c >> x;
    x--;
    st.erase(st.find(cnt[x]));
    if(c == '+') cnt[x]++;
    else cnt[x]--;
    st.insert(cnt[x]);
    yes(*st.begin() >= 8 || (*st.begin() >= 4 && *next(st.begin()) >= 4) || (*st.begin() >= 6 && *next(st.begin()) >= 2) || (*st.begin() >= 4 && *next(st.begin()) >= 2 && *next(st.begin(), 2) >= 2));
  }
}