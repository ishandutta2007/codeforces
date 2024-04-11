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
  vector<P> ans;
  vector<bool> done(n);
  cout << "? 1" << "\n";
  cout.flush();
  vector<int> d1(n);
  REP(i, n) cin >> d1[i];
  int odd = 0;
  int even = 0;
  FOR(i, 1, n) {
    if(d1[i]%2 == 0) even++;
    else odd++;
  }
  if(even <= odd) {
    REP(i, n) if(d1[i] == 1) ans.push_back(P(0, i));
    REP(i, n) if(d1[i] >= 2 && d1[i]%2 == 0) {
      cout << "? " << i+1 << "\n";
      cout.flush();
      vector<int> d(n);
      REP(j, n) cin >> d[j];
      REP(j, n) if(d[j] == 1) ans.push_back(P(i, j));
    }
  } else {
    REP(i, n) if(d1[i]%2 == 1) {
      cout << "? " << i+1 << "\n";
      cout.flush();
      vector<int> d(n);
      REP(j, n) cin >> d[j];
      REP(j, n) if(d[j] == 1) ans.push_back(P(i, j));
    }
  }
  cout << "!" << endl;
  REP(i, n-1) cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
  cout.flush();
}