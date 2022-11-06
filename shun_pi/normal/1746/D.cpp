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
struct Node;
vector<Node> V;
struct Node {
  lint c, s;
  vector<int> nbr;
  PL dfs(lint _c) {
    c = _c;
    if(nbr.size() == 0) return PL(c*s, s);
    lint a = c / nbr.size();
    lint b = c % nbr.size();
    lint score = c * s;
    vector<lint> d;
    for(int x : nbr) {
      PL ret = V[x].dfs(a);
      score += ret.first;
      d.push_back(ret.second);
    }
    sort(ALL(d), greater<lint>());
    REP(i, b) score += d[i];
    return PL(score, d[b] + s);
  };
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    lint n, k;
    cin >> n >> k;
    V = vector<Node>(n);
    vector<int> p(n-1);
    REP(i, n-1) cin >> p[i];
    REP(i, n) cin >> V[i].s;
    REP(i, n-1) V[p[i]-1].nbr.push_back(i+1);
    
    cout << V[0].dfs(k).first << "\n";
  }
}