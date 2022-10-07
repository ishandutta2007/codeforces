#include <bits/stdc++.h>
using namespace std;

#define pow pw
#define p(a) cerr << #a << ":" << (a) << "\n"
#define pp(a, b) p(a), p(b)

typedef long long ll;
const ll MOD = 1E9+9;

ll mul(ll a, ll b) {
  return (a * b) % MOD;
}

ll pow(ll a, ll b) {
  if (b == 0) return 1;
  ll c = pow(a, b / 2);
  c = mul(c, c);
  if (b & 1) c = mul(c, a);
  return c;
}

ll inv(ll a) {
  return pow(a, MOD - 2);
}

ll add(ll a, ll b) {
  return (a + b) % MOD;
}

ll sub(ll a, ll b) {
  return add(a, MOD - b);
}


int n, a, b, k;
string inp;
int main() {
  cin >> n >> a >> b >> k;
  cin >> inp;

  long long x = 0;
  long long s = pow(a, n);
  long long fac = mul(inv(a), b);
  for(int i = 0; i < k; ++i) {
    if (inp[i] == '+') {
      x = add(x, s);
    } else {
      x = sub(x, s);
    }
    s = mul(s, fac);
  }
  long long r = pow(fac, k);
  long long y;
  if (r == 1) {
    y = (n+1)/k;
  } else {
    y = mul(sub(pow(r, (n + 1)/k), 1), inv(sub(r, 1)));
  }
  long long ans = mul(x, y);

  cout << ans << "\n";
}