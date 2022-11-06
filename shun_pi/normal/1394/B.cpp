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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<P>> nbr(n);
  REP(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    nbr[u].push_back(P(w, v));
  }
  REP(i, n) if(nbr[i].size() > 0) sort(ALL(nbr[i]));
  vector<vector<P>> innbr(n);
  REP(i, n) {
    REP(j, nbr[i].size()) {
      innbr[nbr[i][j].second].push_back(P(nbr[i].size()-1, j));
    }
  }
  vector<vector<int>> cnt(k, vector<int>(k));
  vector<vector<vector<vector<bool>>>> rule(k, vector<vector<vector<bool>>>(k, vector<vector<bool>>(k, vector<bool>(k))));
  REP(i, n) {
    map<P, int> pacnt;
    REP(j, innbr[i].size()) {
      pacnt[innbr[i][j]]++;
    }
    for(auto itr=pacnt.begin(); itr!=pacnt.end(); itr++) {
      P key = itr->first;
      int val = itr->second;
      if(val >= 2) cnt[key.first][key.second] = -INF;
      cnt[key.first][key.second]++;
    }
    for(auto itr1=pacnt.begin(); itr1!=pacnt.end(); itr1++) {
      for(auto itr2=next(itr1); itr2!=pacnt.end(); itr2++) {
        rule[itr1->first.first][itr1->first.second][itr2->first.first][itr2->first.second] = true;
      }
    }
  }
  lint ans = 0;
  int loop = 1;
  FOR(i, 1, k+1)loop *= i;
  REP(bit, loop) {
    vector<int> c(k);
    int tmp = bit;
    REP(i, k) {
      c[i] = tmp%(i+1);
      tmp /= i+1;
    }
    bool flg = false;
    REP(i, k) FOR(j, i+1, k) {
      if(rule[i][c[i]][j][c[j]]) {
        flg = true;
        break;
      }
    }
    if(flg) continue;
    lint sum = 0;
    REP(i, k) sum += cnt[i][c[i]];
    if(sum == n) ans++;
  }
  cout << ans << endl;
}