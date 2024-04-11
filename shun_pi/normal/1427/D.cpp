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
vector<int> csort(vector<int> &c, vector<int> &tmp) {
  vector<int> ret;
  int ptr = c.size();
  IREP(i, tmp.size()) {
    ptr -= tmp[i];
    REP(j, tmp[i]) ret.push_back(c[ptr+j]);
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  REP(i, n) cin >> c[i];
  REP(i, n) c[i]--;
  int opes = 0;
  vector<vector<int>> ans;
  while(true) {
    bool comp = true;
    REP(i, n) if(c[i] != i) {
      comp = false;
      break;
    }
    if(comp) break;
    vector<int> tmp;
    REP(i, opes) tmp.push_back(1);
    if((n-opes)%2 == 0) {
      REP(i, n) if(c[i] == opes) {
        tmp.push_back(i+1-opes);
        if(n-1-i > 0) tmp.push_back(n-1-i);
        break;
      }
    } else {
      REP(i, n) if(c[i] == opes) {
        tmp.push_back(n-opes-i);
        if(i > 0) tmp.push_back(i);
        break;
      }
      reverse(ALL(tmp));
    }
    if(tmp.size() > 1) {
      ans.push_back(tmp);
      c = csort(c, tmp);
    }
    opes++;
  }
  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i].size() << " ";
    REP(j, ans[i].size()) cout << ans[i][j] << (j!=ans[i].size()-1 ? " " : "");
    cout << "\n";
  }
  
}