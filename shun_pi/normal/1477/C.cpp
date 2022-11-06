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
  vector<lint> x(n), y(n);
  REP(i, n) cin >> x[i] >> y[i];
  lint mx = 0;
  int s = 0;
  REP(i, n) FOR(j, i+1, n) {
    if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) > mx) {
      mx = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
      s = i;
    }
  }
  vector<int> ans;
  vector<bool> done(n);
  ans.push_back(s);
  done[s] = true;
  REP(i, n-1) {
    lint mx = 0;
    int ne = 0;
    REP(j, n) {
      if(done[j]) continue;
      if((x[s]-x[j])*(x[s]-x[j]) + (y[s]-y[j])*(y[s]-y[j]) > mx) {
        mx = (x[s]-x[j])*(x[s]-x[j]) + (y[s]-y[j])*(y[s]-y[j]);
        ne = j;
      }
    }
    ans.push_back(ne);
    done[ne] = true;
    s = ne; 
  }
  REP(i, n) cout << ans[i]+1 << (i!=n-1 ? " " : "");
  cout << "\n";
}