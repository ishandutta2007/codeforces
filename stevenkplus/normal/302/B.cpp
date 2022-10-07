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

// CURRENT STREAK (fun level): 3 AC in a row
// CURRENT STREAK (easy level): 0 AC in a row

int main() {
  int n, m;
  cin >> n >> m;
  int cur = 0;
  vector<pii> v;
  for (int i = 0; i < n; ++i) {
    int c, t;
    cin >> c >> t;
    cur += c * t;
    v.push_back(pii(cur, i + 1));
  }
  // v.push_back(pii(inf, n));
  sort(v.begin(), v.end());
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    pii res = *lower_bound(v.begin(), v.end(), pii(x, 0));
    cout << res.se << "\n";
  }
}