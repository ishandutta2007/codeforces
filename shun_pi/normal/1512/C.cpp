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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int zeros = 0;
    int ones = 0;
    int l = 0;
    int r = s.size()-1;
    bool ok = true;
    while(l <= r) {
      if(l == r) {
        if(s[l] == '0') zeros++;
        else if(s[l] == '1') ones++;
        else if(a%2 == 1) {
          s[l] = '0';
          zeros++;
        } else {
          s[l] = '1';
          ones++;
        }
        break;
      }
      if(s[l] == '?' && s[r] == '?') {
        //
      } else if(s[l] == '?') {
        s[l] = s[r];
        if(s[r] == '0') zeros += 2;
        else ones += 2;
      } else if(s[r] == '?') {
        s[r] = s[l];
        if(s[l] == '0') zeros += 2;
        else ones += 2;
      } else if(s[l] != s[r]) {
        ok = false;
        break;
      } else {
        if(s[l] == '0') zeros += 2;
        else ones += 2;
      }
      l++;
      r--;
    }
    l = 0;
    r = s.size()-1;
    while(l < r) {
      if(s[l] == '?' && s[r] == '?') {
        if(zeros < a) {
          s[l] = '0';
          s[r] = '0';
          zeros += 2;
        } else {
          s[l] = '1';
          s[r] = '1';
          ones += 2;
        }
      }
      l++;
      r--;
    }
    if(ok && zeros == a && ones == b) {
      cout << s << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}