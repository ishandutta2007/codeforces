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
struct Query {
  int x, y, idx;
};
struct Bit {
  vector<int> bit;
  Bit(int N) : bit(N+1) {};
  void add(int a, int w) {
    while(a < bit.size()) {
      bit[a] += w;
      a += a & -a;
    }
  }
  int sum(int a) {
    int s = 0;
    while(a > 0) {
      s += bit[a];
      a -= a & -a;
    }
    return s;
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  REP(i, n) a[i]--;
  vector<Query> que(q);
  REP(i, q) {
    cin >> que[i].x >> que[i].y;
    que[i].y = n-1 - que[i].y;
    que[i].idx = i;
  }
  sort(ALL(que), [](auto const &a, auto const &b) { return a.y < b.y; });
  vector<int> ans(q);
  Bit bit(n);
  int qidx = 0;
  REP(i, n) {
    if(a[i] <= i) {
      int l = n-2-i;
      int r = n;
      while(r-l > 1) {
        int m = (l+r) / 2;
        if(bit.sum(m+1) >= i - a[i]) {
          r = m;
        } else {
          l = m;
        }
      }
      //cout << r << endl;
      if(r < n) bit.add(r+1, 1);
    }
    while(qidx < q && que[qidx].y == i) {
      ans[que[qidx].idx] = bit.sum(n-que[qidx].x);
      qidx++;
    }
  }
  REP(i, q) cout << ans[i] << "\n";
}