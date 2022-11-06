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
  int ptr1 = 0;
  int ptr2 = 1;
  REP(i, n*n) {
    int a;
    cin >> a;
    if(ptr1 >= n*n) {
      int b = 2;
      if(a == 2) b = 3;
      int i = ptr2/n + 1;
      int j = ptr2%n + 1;
      if(n%2 == 0 && i%2 == 0) j = n+1-j;
      cout << b << " " << i << " " << j << "\n";
      cout.flush();
      ptr2 += 2;
    } else if(ptr2 >= n*n) {
      int b = 1;
      if(a == 1) b = 3;
      int i = ptr1/n + 1;
      int j = ptr1%n + 1;
      if(n%2 == 0 && i%2 == 0) j = n+1-j;
      cout << b << " " << i << " " << j << "\n";
      cout.flush();
      ptr1 += 2;
    } else {
      if(a != 1) {
        int i = ptr1/n + 1;
        int j = ptr1%n + 1;
        if(n%2 == 0 && i%2 == 0) j = n+1-j;
        cout << 1 << " " << i << " " << j << "\n";
        cout.flush();
        ptr1 += 2;
      } else {
        int i = ptr2/n + 1;
        int j = ptr2%n + 1;
        if(n%2 == 0 && i%2 == 0) j = n+1-j;
        cout << 2 << " " << i << " " << j << "\n";
        cout.flush();
        ptr2 += 2;
      }
    }
  }
}