#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MD = 998244353;

ll step(ll a, ll st) {
  if (st == 0) return 1;
  if (st % 2 == 1) return step(a, st - 1) * a % MD;
  ll q = step(a, st / 2);
  return q * q % MD;
}

ll bak(ll a) {
  return step(a, MD - 2);
}

struct Frac {
  ll top, bot;
  Frac(ll top = 0, ll bot = 1): top(top % MD), bot(bot % MD) {}
  Frac operator*(const ll &x) { return Frac(top * (x % MD), bot); }
  Frac operator*(const Frac &f) { return Frac(top * f.top, bot * f.bot); }
  Frac operator+(const Frac &f) {
    return Frac(top * f.bot + f.top * bot, bot * f.bot);
  }
  ll toLong() {
    ll g = __gcd(top, bot);
    top /= g;
    bot /= g;
    return top * bak(bot) % MD;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  vector<ll> pref(n + 1, 0);
  for (int &x : d) cin >> x;
  sort(d.begin(), d.end());
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + d[i];
  }

  while (m--) {
    int a, b;
    cin >> a >> b;

    int num = d.end() - lower_bound(d.begin(), d.end(), b);
    if (num < a) {
      cout << "0\n";
      continue;
    }

    int x = num - a;

    ll weak = pref[n - num];
    ll strong = pref.back() - weak;

    Frac f = Frac(x, a + x) * strong + Frac(x + 1, a + x + 1) * weak;
    cout << f.toLong() << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
#ifdef SERT
  t = 1;
#endif
  while (t--) solve();
}