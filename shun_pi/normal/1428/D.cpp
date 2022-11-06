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
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  vector<P> ans;
  set<P> one;
  set<P> two;
  int row = n-1;
  bool error = false;
  IREP(i, n) {
    if(a[i] == 1) {
      ans.push_back(P(row, i));
      one.insert(P(row, i));
      row--;
    } else if(a[i] == 2) {
      if(one.size() == 0) error = true;
      else {
        P tmp = *one.begin();
        one.erase(tmp);
        ans.push_back(P(tmp.first, i));
        two.insert(P(tmp.first, i));
      }
    } else if(a[i] == 3) {
      if(two.size() > 0) {
        P tmp = *two.begin();
        two.erase(tmp);
        ans.push_back(P(row, tmp.second));
        ans.push_back(P(row, i));
        two.insert(P(row, i));
        row--;
      } else if(one.size() > 0) {
        P tmp = *one.begin();
        one.erase(tmp);
        ans.push_back(P(row, tmp.second));
        ans.push_back(P(row, i));
        two.insert(P(row, i));
        row--;
      } else error = true;
    }
  }
  if(error) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans.size() << "\n";
  REP(i, ans.size()) cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
}