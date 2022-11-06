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
    vector<vector<int>> rnbr(n);
    REP(i, n) {
      int k;
      cin >> k;
      REP(j, k) {
        int x;
        cin >> x;
        x--;
        rnbr[i].push_back(x);
        nbr[x].push_back(i);
      }
    }
    set<int> now;
    vector<int> cnt(n);
    REP(i, n) {
      cnt[i] = rnbr[i].size();
      if(cnt[i] == 0) now.insert(i);
    }
    int ans = 0;
    while(true) {
      set<int> next;
      if(now.size() == 0) break;
      auto itr = now.begin();
      while(itr != now.end()) {
        int x = *itr;
        for(int y : nbr[x]) {
          cnt[y]--;
          if(cnt[y] == 0) {
            if(y < x) next.insert(y);
            else now.insert(y);
          }
        }
        itr++;
      }
      ans++;
      now = next;
    }
    REP(i, n) if(cnt[i] > 0) ans = -1;
    cout << ans << "\n";
  }
}