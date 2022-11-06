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
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--; c--;
    int g = 1;
    REP(i, c) g *= 10;
    a -= c;
    b -= c;
    int ansa = 1;
    REP(i, a) ansa *= 10;
    while(true) {
      bool ok = true;
      if(ansa%2 == 0) ok = false;
      for(int i=3; i*i<=ansa; i+=2) if(ansa%i == 0) ok = false;
      if(ok) break;
      ansa++;
    }
    int ansb = 1;
    REP(i, b) ansb *= 10;
    while(true) {
      bool ok = true;
      if(ansb%2 == 0) ok = false;
      if(ansb == ansa) ok = false;
      for(int i=3; i*i<=ansb; i+=2) if(ansb%i == 0) ok = false;
      if(ok) break;
      ansb++;
    }
    cout << ansa*g << " " << ansb*g << "\n";
  }
}