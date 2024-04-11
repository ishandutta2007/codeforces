#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll s, x;
int main() {
  cin >> s >> x;
  ll diff = s - x;
  if ((diff & (x << 1)) || diff & 1) {
    cout << "0\n";
    return 0;
  }

  ll ans = 1;
  for(int i = 0; i < 60; ++i) {
    if ((x >> i) & 1) {
      ans *= 2;
    }
  }

  if (s == x) {
    ans -= 2; // positive integers
  }
  cout << ans << "\n";
  return 0;
}