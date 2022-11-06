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
lint gcd(lint a, lint b) {
  if(a < b) {
    swap(a, b);
  }
  while(b > 0) {
    lint r = a % b;
    a = b;
    b = r;
  }
  return a;
}
lint lcm(lint a, lint b) {
  return a * b / gcd(a, b);
}
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
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    lint target = a[0];
    FOR(i, 1, n) target = gcd(target, a[i]);
    int cnt = 0;
    vector<bool> cnted(n);
    REP(i, n) if(a[i] == target) {
      cnt++;
      cnted[i] = true;
    }
    int ans = 0;
    set<int> need;
    REP(i, n) need.insert(i);
    while(true) {
      if(cnt == n) break;
      set<int> next;
      int a0tmp = a[0];
      for(int x : need) {
        int tmp = a[x];
        a[x] = gcd(a[x], x == n-1 ? a0tmp : a[x+1]);
        if(a[x] != tmp) {
          next.insert(x);
          next.insert((x-1+n)%n);
        }
        if(!cnted[x] && a[x] == target) {
          cnt++;
          cnted[x] = true;
        }
      }
      need = next;
      ans++;
    }
    cout << ans << "\n";
  }
}