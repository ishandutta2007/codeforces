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
    int n, m;
    cin >> n >> m;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    a.push_back(1e18);
    a.push_back(-1e18);
    sort(ALL(a));
    vector<PL> lr;
    REP(i, m) {
      lint l, r;
      cin >> l >> r;
      auto itr = lower_bound(ALL(a), l);
      if(!(itr != a.end() && *itr <= r)) {
        lr.push_back(PL(l, r));
      }
    }
    sort(ALL(lr));
    
    lint anext = 1;
    lint lrtmp = 0;
    lint lridx = 0;
    map<lint, lint> lasttable;
    lasttable[0] = 0;
    lint lastfullmin = 0;
    while(anext < a.size()) {
      if(lridx == lr.size() || lr[lridx].first > a[anext]) {
        multiset<lint> rset;
        FOR(i, lrtmp, lridx) rset.insert(lr[i].second);
        map<lint, lint> nexttable;
        //dl == 0
        lint dr = 0;
        if(rset.size() > 0) dr = a[anext] - *rset.begin();
        nexttable[dr] = lastfullmin + dr + dr;
        lint nextfullmin = lastfullmin + dr;
        FOR(i, lrtmp, lridx) {
          lint dl = lr[i].first - a[anext-1];
          rset.erase(rset.find(lr[i].second));
          lint dr = 0;
          if(rset.size() > 0) dr = a[anext] - *rset.begin();
          lint next = prev(lasttable.lower_bound(dl))->second + dl;
          chmin(next, lastfullmin + dl + dl);
          if(nexttable.find(dr) == nexttable.end()) nexttable[dr] = next + dr + dr;
          else chmin(nexttable[dr], next + dr + dr);
          chmin(nextfullmin, next + dr); 
        }
        lint tmp = 1e18;
        for (const auto& [key, value] : nexttable){
          //cout << key << " " << value << endl;
          chmin(tmp, value);
          nexttable[key] = tmp;
        }

        lasttable = nexttable;
        lastfullmin = nextfullmin;
        anext++;
        lrtmp = lridx;
      } else {
        lridx++;
      }
    }
    cout << lastfullmin << "\n";
  }
}