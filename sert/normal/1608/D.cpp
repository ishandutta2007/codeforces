#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MD = 998244353;
#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif

struct init_t {
  vector<ll> fac;
  vector<ll> ofac;
  explicit init_t(int N = 3e5) {
    fac.assign(N, 1);
    for (int i = 1; i < N; i++) {
      fac[i] = fac[i - 1] * i % MD;
    }
    ofac.assign(N, my_pow(fac.back(), MD - 2));
    for (int i = N - 2; i >= 0; i--) {
      ofac[i] = ofac[i + 1] * (i + 1) % MD;
    }
  }

  ll my_pow(ll a, ll pow) const {
    if (pow == 0) return 1;
    if (pow % 2) return a * my_pow(a, pow - 1) % MD;
    ll q = my_pow(a, pow / 2);
    return q * q % MD;
  }
};

void solve(const init_t &data) {
  auto getC = [&data](int n, int k) -> long long {
    if (k < 0 || k > n) return 0LL;
    return data.fac[n] * data.ofac[k] % MD * data.ofac[n - k] % MD;
  };
  int n;
  cin >> n;
  ll num2 = 0;
  bool same = false;
  int lb = 0, lw = 0, rb = 0, rw = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "??") num2++;
    if (s[0] == s[1] && s[0] != '?') same = true;
    if (s[0] == 'B') lb++;
    if (s[0] == 'W') lw++;
    if (s[1] == 'B') rb++;
    if (s[1] == 'W') rw++;
  }
  int leftR = n - rb - rw;

  ll ans = 0;
  if (!same) {
    ans = MD - data.my_pow(2, num2);
    if (lw == 0 && rb == 0) ans++;
    if (lb == 0 && rw == 0) ans++;
    ans %= MD;
  }
  for (int LB = lb; LB + lw <= n; LB++) {
    int LW = n - LB;
    //cout << LB << " " << LW << "\n";
    if (LW < lw) continue;
    ll cur = getC(n - lb - lw, LB - lb);
    int rb_add = LW - rb;
    int rw_add = LB - rw;
    if (rb_add >= 0 && rw_add >= 0) {
      cur = cur * getC(leftR, rb_add) % MD;
      ans = (ans + cur) % MD;
    }
  }

  cout << ans << "\n";
}

int main() {
  init_t data;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  //cin >> t;
  while (t--) {
    solve(data);
  }
}