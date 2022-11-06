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
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    int ra = 5;
    int rb = 5;
    int ans1 = 0;
    REP(i, s.size()) {
      if(i%2 == 0) {
        if(s[i] != '0') a++;
        ra--;
      } else {
        if(s[i] == '1') b++;
        rb--;
      }
      if(i == s.size()-1 || a > b + rb) {
        ans1 = i+1;
        break;
      }
    }
    a = 0;
    b = 0;
    ra = 5;
    rb = 5;
    int ans2 = 0;
    REP(i, s.size()) {
      if(i%2 == 0) {
        if(s[i] == '1') a++;
        ra--;
      } else {
        if(s[i] != '0') b++;
        rb--;
      }
      if(i == s.size()-1 || b > a + ra) {
        ans2 = i+1;
        break;
      }
    }
    cout << min(ans1, ans2) << "\n";
  }
}