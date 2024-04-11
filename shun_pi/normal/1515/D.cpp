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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> lc(n), rc(n);
    if(l > r){
      swap(l, r);
      REP(i, r) {
        int x;
        cin >> x;
        rc[x-1]++;
      }
      REP(i, l) {
        int x;
        cin >> x;
        lc[x-1]++;
      }
    } else {
      REP(i, l) {
        int x;
        cin >> x;
        lc[x-1]++;
      }
      REP(i, r) {
        int x;
        cin >> x;
        rc[x-1]++;
      }
    }
    int ans = 0;
    REP(i, n) {
      int mi = min(lc[i], rc[i]);
      lc[i] -= mi;
      rc[i] -= mi;
      l -= mi;
      r -= mi;
    }
    REP(i, n) {
      int p = min((r-l)/2, rc[i] / 2);
      ans += p;
      rc[i] -= p * 2;
      r -= p*2;
    }
    ans += (r - l) / 2;
    ans += (l + r) / 2;
    cout << ans << "\n";
  }
}