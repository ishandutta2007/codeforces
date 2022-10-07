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
// CURRENT STREAK (easy level): 3 AC in a row
// CURRENT STREAK (medium level): 1 AC in a row


int main() {
  int n;
  cin >> n;
  map<pii, int> mp;
  map<int, int> cnts;
  for (int i = 0; i < n - 2; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    mp[pii(a, b)] ^= c;
    mp[pii(b, a)] ^= c;
    mp[pii(a, c)] ^= b;
    mp[pii(c, a)] ^= b;
    mp[pii(b, c)] ^= a;
    mp[pii(c, b)] ^= a;
    ++cnts[a];
    ++cnts[b];
    ++cnts[c];
  }

  int a = -1, b = -1, c = -1;
  for (int i = 1; i <= n; ++i) {
    if (cnts[i] == 1) {
      a = i;
    } else if (cnts[i] == 2) {
      if (b == -1) b = i;
      else c = i;
    }
  }
  pp(a, b, c, mp[pii(a, b)]);
  if (!mp[pii(a, b)]) {
    b = c;
  }
  cout << a << " " << b;
  int prv = 0;
  for (int i = 2; i < n; ++i) {
    int c = mp[pii(a, b)] ^ prv;
    cout << " " << c;
    prv = a;
    a = b;
    b = c;
  }
  cout << "\n";
}