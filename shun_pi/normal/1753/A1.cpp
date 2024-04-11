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
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int sum = 0;
    REP(i, n) sum += a[i];
    if(abs(sum)%2 != 0) {
      cout << -1 << "\n";
      continue;
    }
    sum /= 2;
    bool lastminus = true;
    vector<int> ans;
    REP(i, n) {
      if(a[i] == 0) {
        lastminus = false;
        ans.push_back(i);
        continue;
      }
      if(lastminus) {
        lastminus = false;
        ans.push_back(i);
        continue;
      }
      else {
        if(sum > 0 && a[i] == 1) {
          sum--;
          lastminus = true;
        } else if(sum < 0 && a[i] == -1) {
          sum++;
          lastminus = true;
        } else {
          ans.push_back(i);
        }
      }
    }
    if(ans[ans.size()-1] != n) ans.push_back(n);
    if(sum == 0) {
      cout << ans.size() - 1 << "\n";
      REP(i, ans.size() - 1) cout << ans[i]+1 << " " << ans[i+1] << "\n";
    } else cout << -1 << endl;
  }
}