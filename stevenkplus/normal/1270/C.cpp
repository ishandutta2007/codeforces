#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll BIG = 1LL << 50;

const int MAXN = 200100;
ll ar[MAXN];
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    ll x = 0, s = 0;
    for(int i = 0; i < n; ++i) {
      cin >> ar[i];
      x ^= ar[i];
      s += ar[i];
    }
    ll a = BIG;
    if (s % 2 == 1) a += 1;
    x ^= a;
    s += a;
    ll d = (2 * x - s) / 2;
    cout << "3\n";
    cout << a << " " << d << " " << d << "\n";
  }
}