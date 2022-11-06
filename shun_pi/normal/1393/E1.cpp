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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  vector<pair<string, lint>> las;
  las.push_back(make_pair("", 1LL));
  REP(i, n) {
    vector<pair<string, lint>> tmp;
    REP(j, s[i].size()+1) {
      string str = s[i];
      if(j < s[i].size()) str = s[i].substr(0, j) + s[i].substr(1+j, s[i].size()-1-j);
      lint l = -1;
      lint r = las.size();
      while(r-l > 1) {
        lint m = (l+r) / 2;
        if(las[m].first <= str) l = m;
        else r = m;
      }
      if(l == -1) continue;
      if(i == n-1) str = "";
      else if(str.size() > s[i+1].size()+1) str = str.substr(0, s[i+1].size()+1);
      tmp.push_back(make_pair(str, las[l].second));
    }
    sort(ALL(tmp));
    FOR(j, 1, tmp.size()) tmp[j].second = (tmp[j].second + tmp[j-1].second) % MOD;
    las.clear();
    las = tmp;
    //REP(j, las.size()) cout << las[j].first << " " << las[j].second << endl;
  }
  if(las.size() == 0) cout << 0 << endl;
  else cout << las[las.size()-1].second << endl;
}