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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    lint n; string a;
    cin >> n >> a;
    vector<lint> S(n+1);
    REP(i, n) S[i+1] = S[i] + (a[i]-'0');
    map<lint, lint> mp;
    REP(i, n+1) mp[S[i]-i]++;
    lint ans = 0;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
      lint val = itr->second;
      ans += val*(val-1)/2;
    }
    cout << ans << "\n";
  }
}