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
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    REP(i, n) a[i]--;
    unordered_map<int, vector<int>> mp;
    REP(i, n) mp[a[i]].push_back(i);
    vector<int> b(n);
    while(!mp.empty()) {
      vector<int> erasekey;
      vector<int> keylist, vallist;
      for (auto const& [key, val] : mp) {
        keylist.push_back(key);
        vallist.push_back(val[val.size()-1]);
        mp[key].pop_back();
        if(mp[key].size() == 0) erasekey.push_back(key);
      }
      REP(i, keylist.size()) {
        b[vallist[(i+1)%keylist.size()]] = keylist[i];
      }
      for(int x : erasekey) mp.erase(x);
    }
    REP(i, n) cout << b[i]+1 << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}