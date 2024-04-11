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
lint gcd(lint a, lint b) {
  if(a < b) {
    swap(a, b);
  }
  while(b > 0) {
    lint r = a % b;
    a = b;
    b = r;
  }
  return a;
}
lint lcm(lint a, lint b) {
  return a * b / gcd(a, b);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  int ans2 = 0;
  map<int, int> mp;
  vector<int> ans(n);
  int r = 0;
  REP(i, n) {
    if(a[i] == 1) {
      ans2++;
      ans[i] = ans2;
      mp.clear();
      r = i + 1;
      continue;
    }
    map<int, int> nmp;
    
    int l = r;
    bool ok = false;
    for (auto const& [key, val] : mp) {
      int g = gcd(key, a[i]);
      if(i-val+1 <= g && g <= i-l+1) {
        ans2++;
        r = i + 1;
        nmp.clear();
        ok = true;
        break;
      }
      nmp[g] = val;
      l = val + 1;
    }
    if(!ok) nmp[a[i]] = i;

    ans[i] = ans2;
    mp = nmp;
  }
  REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
  cout << "\n";
}