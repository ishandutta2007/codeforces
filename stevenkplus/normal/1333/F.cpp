// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //


// ========== Solution ========== //

const int MAXN = 500500;
bool isp[MAXN];

int __gcd(int a, int b) {
  if (a == 0) return b;
  return __gcd(b % a, a);
}

int main() {
  for (int i = 1; i < MAXN; ++i) isp[i] = true;
  for (int i = 2; i < MAXN; ++i) {
    for (int j = i + i; j < MAXN; j += i) {
      isp[j] = false;
    }
  }
  int n;
  cin >> n;
  vector<vector<int>> layers(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (isp[i]) {
      layers[1].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= i && i * j <= n; ++j) {
      if (isp[j] && __gcd(i, j) == 1) {
        layers[i].push_back(i * j);
      } else if (isp[j]) {
        layers[i].push_back(i * j);
        break;
      }
    }
  }
  pp(layers);
  int j = 0;
  int sum = 0;
  for (int i = 2; i <= n; ++i) {
    while (sum < i) {
      ++j;
      sum += sz(layers[j]);
    }
    cout << j << " ";
  }
  cout << "\n";
}