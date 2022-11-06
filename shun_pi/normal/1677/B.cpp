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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ans(n*m);
    vector<bool> col(m);
    int now = 0;
    REP(i, n*m) {
      if(s[i] == '1') {
        if(!col[i%m]) {
          now++;
          col[i%m] = true;
        }
      }
      ans[i] = now;
    }
    vector<int> sum(n*m+1);
    REP(i, n*m) sum[i+1] = sum[i] + (s[i] == '1' ? 1 : 0);
    REP(i, m) {
      int now = 0;
      if(sum[i+1] - sum[0] > 0) now++;
      REP(j, n) {
        ans[j*m+i] += now;
        if(j == n-1) break;
        if(sum[i+1+(j+1)*m] - sum[i+1+j*m] > 0) now++;
      }
    }
    REP(i, n*m) cout << ans[i] << (i!=n*m-1 ? " " : "");
    cout << "\n";
  }
}