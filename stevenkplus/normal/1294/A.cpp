// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// CURRENT STREAK: 2 AC in a row

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int target = (a + b + c + n);
    if (target % 3) {
        cout << "NO\n";
    } else {
      target /= 3;
      if (target >= a && target >= b && target >= c) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}