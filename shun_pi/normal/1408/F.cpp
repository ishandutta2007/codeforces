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
  vector<P> ans;
  int l = 1;
  while(l <= n) {
    for(int idx=0; idx+l*2-1<n; idx+=l*2) {
      REP(i, l) ans.push_back(P(idx+i, idx+l+i));
    }
    l *= 2;
  }
  int ntmp = n;
  vector<int> setsize;
  while(ntmp > 0) {
    int tmp = 1;
    while(true) {
      if(tmp*2 > ntmp) break;
      tmp *= 2;
    }
    setsize.push_back(tmp);
    ntmp -= tmp;
  }
  vector<int> setidx(setsize.size());
  FOR(i, 1, setidx.size()) setidx[i] = setidx[i-1] + setsize[i-1];
  if(setsize.size() >= 3) {
    vector<int> lastset;
    FOR(i, setidx[setsize.size()-1], setidx[setsize.size()-1]+setsize[setsize.size()-1]) {
      lastset.push_back(i);
    }
    int ptr = 0;
    int target = setsize.size()-2;
    while(target > 0) {
      int l = lastset.size();
      if(l == setsize[target]) {
        REP(i, l) {
        ans.push_back(P(lastset[i], setidx[target]+i));
        lastset.push_back(setidx[target]+i);
        }
        target--;
      } else {
        REP(i, l) {
          ans.push_back(P(lastset[i], ptr));
          lastset.push_back(ptr);
          ptr++;
        }
      }
    }
  }
  
  cout << ans.size() << "\n";
  REP(i, ans.size()) cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";

  vector<lint> v(n);
  REP(i, n) v[i] = i+1;
  REP(i, ans.size()) {
    int x = ans[i].first;
    int y = ans[i].second;
    lint t = v[x] + v[y];
    v[x] = t; v[y] = t;
  }
  set<lint> st;
  REP(i, n) st.insert(v[i]);
  //cout << st.size() << endl;
}