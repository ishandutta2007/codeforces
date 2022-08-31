#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void exgcd(ll x, ll y, ll &a, ll &b) {
  if (!y) {
    a = 1;
    b = 0;
 } else {
   exgcd(y, x % y, b, a);
   b -= x / y * a;
 }
}

ll my_div(ll x, ll y) {
  if (!y) {
    return 1ll << 60;
  } else {
    return x >= 0 ? (x + y - 1) / y : x / y;
  }
}

ll solve(ll x, ll y, ll n, ll m, int type) {
  if (m < x + type) {
    return -1;
  }
  m -= x;
  if (n <= 1e6) {
    for (int answer = n; ~answer; --answer) {
      int each = answer + n;
      ll t = my_div(m - min(x, m), each);
      while (t * each <= m - type) {
        ll a = m - t * each, b = answer - a;
        if (b >= 0 && b <= y) {
          return answer;
        }
        ++t;
      }
    }
    return -1;
  } else {
    ll answer = -1;
    for (int t = 0; n * t <= m; ++t) {
      ll c = m - n * t;
      if (!c) {
        if (!type) {
          answer = max(answer, t ? 0ll : y);
        }
      } else {
        ll a, b;
        exgcd(t + 1, t, a, b);
        a *= c;
        b *= c;
        if (!t) {
          if (a <= min(x, m) && a >= type) {
            answer = max(answer, a + y);
          }
          continue;
        }
        ll min_k = max(my_div(type - a, t), my_div(b - y, t + 1));
        if (a + min_k * t <= min(x, m) && b - min_k * (t + 1) >= 0) {
          answer = max(answer, a + b - min_k);
        }
      }
    }
    return answer;
  }
}


int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ll n, m, l, r;
  cin >> n >> l >> r >> m;
  ll x = (r - l + n) % n + 1, y = n - x;
  cout << max(solve(x, y, n, m, 0), solve(x, y, n, m + 1, 1)) << endl;
  return 0;
}