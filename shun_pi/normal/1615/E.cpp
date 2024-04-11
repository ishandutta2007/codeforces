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
vector<lint> p;
struct Node {
  int idx;
  vector<int> nbr;
  bool vst = false;
  lint dfs() {
    vst = true;
    vector<lint> ret;
    ret.push_back(0);
    for(int x : nbr) if(!V[x].vst) ret.push_back(V[x].dfs());
    sort(ALL(ret), greater<lint>());
    lint size = ret[0] + 1;
    FOR(i, 1, ret.size()) p.push_back(ret[i]);
    return size;
  };
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint n, k;
    cin >> n >> k;
    V = vector<Node>(n);
    REP(i, n) V[i].idx = i;
    REP(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        V[u].nbr.push_back(v);
        V[v].nbr.push_back(u);
    }
    p.push_back(V[0].dfs());
    sort(ALL(p), greater<lint>());
    lint sum = 0;
    int leaf = 0;
    REP(i, min((lint)p.size(), k)) {
        sum += p[i];
        if(p[i] > 0) leaf++;
    }
    lint ans = -1e18;
    lint b = min(n/2, n - sum);
    FOR(i, leaf, k+1) chmax(ans, (n - i - b) * (i - b));
    cout << ans << endl;
    
}