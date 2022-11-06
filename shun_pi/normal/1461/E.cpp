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
  lint k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  k -= l;
  r -= l;
  lint now = 0;
  vector<bool> seen(x);
  while(true) {
    //cout << now << " " << k << endl;
    if(k > r-y) {
      lint target = max(-1LL, r-y);
      lint d = k - target;
      lint zou = (d - 1) / x + 1;
      now += zou;
      k -= x * zou;
      if(k < 0) {
        yes(t < now);
        return 0;
      }
      if(seen[r-y-k]) {
        cout << "Yes" << endl;
        return 0;
      }
      seen[r-y-k] = true;
    } else {
      if(y-x == 0) {
        cout << "Yes" << endl;
        return 0;
      } else if(y-x > 0) {
        lint target = r-y+1;
        lint d = target - k;
        lint zou = (d - 1) / (y-x) + 1;
        now += zou;
        k += (y-x) * zou;
        if(k > r) {
          yes(t < now);
          return 0;
        }
      } else {
        lint target = -1;
        lint d = k - target;
        lint zou = (d - 1) / (x-y) + 1;
        now += zou;
        k -= (x-y) * zou;
        if(k < 0) {
          yes(t < now);
          return 0;
        }
      }
    }
  }
}