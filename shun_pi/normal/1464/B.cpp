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
  string s;
  cin >> s;
  lint x, y;
  cin >> x >> y;
  lint ones = 0;
  lint zeros = 0;
  REP(i, s.size()) if(s[i] == '1') {
    ones++;
  } else  {
    zeros++;
  }
  lint now = x * ones;
  lint sum = 0;
  REP(i, s.size()) {
    if(s[i] == '0' || s[i] == '?') {
      sum += now;
    } else now = now - x + y;
  }
  lint ans = sum;
  if(x >= y) {
    lint a = ones;
    lint b = 0;
    lint leftzero = 0;
    lint rightzero = zeros;
    REP(i, s.size()) {
      if(s[i] == '?') {
        rightzero--;
        sum -= a * x + b * y;
        sum += leftzero * x;
        sum += rightzero * y;
        b++;
      } else if(s[i] == '1') {
        a--;
        b++;
      } else if(s[i] == '0') {
        rightzero--;
        leftzero++;
      }
      chmin(ans, sum);
    }
  } else {
    lint a = 0;
    lint b = ones;
    lint leftzero = zeros;
    lint rightzero = 0;
    IREP(i, s.size()) {
      if(s[i] == '?') {
        leftzero--;
        sum -= a * x + b * y;
        sum += leftzero * x;
        sum += rightzero * y;
        a++;
      } else if(s[i] == '1') {
        a++;
        b--;
      } else if(s[i] == '0') {
        leftzero--;
        rightzero++;
      }
      chmin(ans, sum);
    }
  }
  cout << ans << endl;
}