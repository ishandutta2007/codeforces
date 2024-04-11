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
  vector<int> vec(1000001);
  FOR(i, 1, 1001) {
    int sq = i * i;
    for(int j=sq; j<1000001; j+=sq) vec[j] = j / sq;
  }
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    map<int, int> mp;
    REP(i, n) mp[vec[a[i]]]++;
    int ans0 = 0;
    int ans1 = 0;
    for(auto itr=mp.begin(); itr != mp.end(); itr++) {
      int key = itr->first;
      int val = itr->second;
      chmax(ans0, val);
      if(key == 1 || val%2 == 0) ans1 += val;
    }
    chmax(ans1, ans0);
    int Q;
    cin >> Q;
    REP(q, Q) {
      lint w;
      cin >> w;
      if(w == 0) cout << ans0 << "\n";
      else cout << ans1 << "\n";
    }
  }
}