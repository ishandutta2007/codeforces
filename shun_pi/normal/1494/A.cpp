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
    int ab = 0;
    int bc = 0;
    int ca = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    REP(i, s.size()) {
      if(s[i] == 'A') {
        if(ab >= 0) ab++;
        if(ca >= 0) ca++;
        if(a >= 0) a++;
        bc--;
        b--;
        c--;
      } else if(s[i] == 'B') {
        if(ab >= 0) ab++;
        if(bc >= 0) bc++;
        ca--;
        a--;
        if(b >= 0) b++;
        c--;
      } else {
        ab--;
        if(bc >= 0) bc++;
        if(ca >= 0) ca++;
        a--;
        b--;
        if(c >= 0) c++;
      }
    }
    yes(ab == 0 || bc == 0 || ca == 0 || a == 0 || b == 0 || c == 0);
  }
}