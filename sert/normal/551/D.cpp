#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MD;

struct M2 {  
  ll a, b, c, d;
  M2(ll a = 0, ll b = 1, ll c = 1, ll d = 1): a(a % MD), b(b % MD), c(c % MD), d(d % MD) {}

  M2 operator * (const M2 &m) const {
    return M2(a * m.a + b * m.c, a * m.b + b * m.d, c * m.a + d * m.c, c * m.b + d * m.d);
  }

  M2 pow(ll step) {
    if (step == 1) return *this;
    if (step % 2 == 1) return pow(step - 1) * (*this);
    auto k = pow(step / 2);
    return k * k;
  }

  friend ostream& operator<<(ostream &fo, M2 m) {
    fo << "[" << m.a << ", " << m.b << "]\n[" << m.c << ", " << m.d << "]\n";
    return fo;
  }
};

ll pow2(ll a, ll step) {
  if (step == 0) return 1;
  if (step % 2) return pow2(a, step - 1) * a % MD;
  ll q = pow2(a, step / 2);
  return q * q % MD;
}

void solve() {
  ll n, k, l;
  cin >> n >> k >> l >> MD;

  if (k >= (1ll << min(62ll, (ll)l))) {
    cout << "0\n";
    return;
  }  

  if (l == 0) {
    cout << 1 % MD << "\n";
    return;
  }  

  M2 m;
  auto mp = m.pow(n);
  ll sum = (mp.b + mp.d) % MD;
  ll sumN = (pow2(2, n) - sum + MD) % MD;

  //cout << sum << " " << sumN << endl;

  ll ans = 1;
  for (ll i = 0; i < l; i++) {
    if (k & (1ll << i))
      ans = (ans * sumN) % MD;
    else
      ans = (ans * sum) % MD;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 1;
#endif

  for (int i = 0; i < t; i++)
    solve();
}