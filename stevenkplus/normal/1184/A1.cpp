#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll a;
  cin >> a;
  for(int i = 1; i <= 1000000; ++i) {
    ll x = i;
    ll val = x * x + x + 1;
    ll y = (a - val);
    if (y <= 0) break;
    if (y % (2 * x) == 0) {
      y /= 2 * x;
      cout << x << " " << y << "\n";
      return 0;
    }
  }
  cout << "NO\n";
}