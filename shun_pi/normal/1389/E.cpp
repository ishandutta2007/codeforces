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
  int T;
  cin >> T;
  while(T--) {
    lint m, d, w;
    cin >> m >> d >> w;
    if(d == 1) {
      cout << 0 << "\n";
      continue;
    }
    w /= gcd(w, d-1);
    lint p = min(m, d) / w;
    lint q = min(m, d) % w;
    lint ans = p*(p-1) / 2 * w;
    ans += p * q;
    cout << ans << "\n";
  }
}