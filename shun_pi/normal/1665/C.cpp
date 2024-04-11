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
    vector<vector<int>> nbr(n);
    REP(i, n-1) {
      int p;
      cin >> p;
      p--;
      nbr[p].push_back(i+1);
    }
    multiset<int, greater<int>> healthy;
    healthy.insert(1);
    REP(i, n) if(nbr[i].size() > 0) healthy.insert(nbr[i].size());
    multiset<int, greater<int>> infected;
    int ans = 0;
    while(true) {
      if(healthy.size() == 0 && infected.size() == 0) break;
      multiset<int, greater<int>> next;
      for(int x : infected) if(x > 1) next.insert(x-1);
      infected = next;
      if(healthy.size() > 0) {
        int x = *healthy.begin();
        healthy.erase(healthy.find(x));
        x--;
        if(x > 0) infected.insert(x);
      } else if(infected.size() > 0) {
        int x = *infected.begin();
        infected.erase(infected.find(x));
        x--;
        if(x > 0) infected.insert(x);
      }
      ans++;
    }
    cout << ans << "\n";
  }
}