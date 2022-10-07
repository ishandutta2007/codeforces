#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int pp(ll x) {
  int ans = 0;
  for (int i = 0; i < 64; ++i) {
    if (x %2) ++ans;
    x /= 2;
  }
  return ans;
}

const int MAXN = 300100;
int vals[MAXN];
int evens[MAXN];
int odds[MAXN];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    int x = pp(a);
    vals[i] = x;
  }
  int parity = 0;
  ll ans = 0;
  evens[0] = 1;

  for (int i = 0; i < n; ++i) {
    int lft = max(0, i - 100);
    int mx = 0;
    int sm = 0;
    for(int j = i; j >= lft; --j) {
      mx = max(mx, vals[j]);
      sm += vals[j];
      if (sm % 2 == 0 && mx + mx <= sm) ++ans;
    }
    evens[i + 1] = evens[i];
    odds[i + 1] = odds[i];
    parity += vals[i];
    parity %= 2;
    if (parity) {
      if (lft > 0) 
      ans += odds[lft - 1];
      odds[i + 1]++;
    } else {
      if (lft > 0) 
      ans += evens[lft - 1];
      evens[i + 1]++;
    }
  }
  cout << ans << "\n";
}