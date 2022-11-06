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
lint ans = 0;
struct Node;
vector<Node> V;
struct Node {
  int idx;
  lint l, r;
  vector<int> nbr;
  bool vst = false;
  int dfs() {
    vst = true;
    lint sum = 0;
    for(int x : nbr) if(!V[x].vst) sum += V[x].dfs();
    if(l > sum) {
      ans++;
      sum = r;
    } else if(sum > r) sum = r;
    return sum;
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
    int n;
    cin >> n;
    V = vector<Node>(n);
    REP(i, n-1) {
      int p;
      cin >> p;
      p--;
      V[i+1].nbr.push_back(p);
      V[p].nbr.push_back(i+1);
    }
    REP(i, n) cin >> V[i].l >> V[i].r;
    ans = 0;
    V[0].dfs();
    cout << ans << "\n";
  }
}