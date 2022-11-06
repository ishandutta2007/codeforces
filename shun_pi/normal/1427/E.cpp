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
struct op{lint a, b; int type;};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint x;
  cin >> x;
  vector<op> ans;
  if(x>>1&1) {
    ans.push_back(op{x, x, 0});
    ans.push_back(op{2*x, x, 1});
    x = (x*2)^x;
  }
  while(x != 1) {
    lint k = 0;
    IREP(i, 60) if(x>>i&1) {
      k = i;
      break;
    }
    lint y = x;
    REP(i, k) {
      ans.push_back(op{y, y, 0});
      y *= 2;
    }
    ans.push_back(op{x, y, 0});
    ans.push_back(op{x, y, 1});
    ans.push_back(op{x+y, x^y, 1});
    lint z = (x+y)^(x^y);
    k++;
    while(true) {
      if(y>>k&1) {
        ans.push_back(op{y, z, 1});
        y ^= z;
      }
      int bit = 0;
      REP(i, 60) if(y>>i&1) bit++;
      if(bit <= 1) break;
      ans.push_back(op{z, z, 0});
      z *= 2;
      k++;
    }
    ans.push_back(op{x, y, 1});
    x ^= y;
    //cout << x << "\n";
  }

  cout << ans.size() << endl;
  REP(i, ans.size()) {
    if(ans[i].type == 0) cout << ans[i].a << " + " << ans[i].b << endl; 
    else cout << ans[i].a << " ^ " << ans[i].b << endl; 
  }
}