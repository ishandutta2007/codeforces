#include <bits/stdc++.h>
using namespace std;

#define gcd ggcd
#define repi(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
typedef long long ll;

map<ll, map<ll, ll> > df;

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd (b % a, a);
}

bool prop(ll a, ll b, ll c, ll d) {
  ll g = gcd(a, b);
  a /= g; b /= g;
  g = gcd(c, d);
  c /= g; d /= g;
  return a == c && b == d;
}

bool eq(ll x1, ll x2) {
  map<ll, ll> &y1 = df[x1];
  map<ll, ll> &y2 = df[x2];

  ll top = 0;
  if (y1.size() != y2.size()) return false;
  repi(i, y1) {
    ll y = i->first;
    if (!top) {
      top = y;
      if (!y2[top]) return false;
    } else {
      if (!prop(y1[top], y1[y], y2[top], y2[y])) {
        return false;
      }
    }
  }
  return true;
}

int n;
ll ans = 0;
bool go() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    ans = gcd(ans, c);
    df[a][b] = c;
  }

  ll top = 0;
  repi(i, df) {
    ll x = i->first;
    if (!top) {
      top = x;
    } else {
      if (!eq(x, top)) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  if (go()) {
    int LIMIT = 2E6;
    int cnt = 0;
    for (ll i = 1; i < LIMIT; ++i) {
      if (ans % i == 0) {
        cnt++;
        if (ans / i >= LIMIT) cnt++;
      }
    }
    cout << cnt << "\n";
  } else {
    cout << 0 << "\n";
  }
}