// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

// =========== Solution ============= //


int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    if (k % 3 == 0) {
      int mod = n % (k + 1);
      if (mod % 3 == 0 && mod < k)  {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    } else {
      if (n % 3 == 0) {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    }
  }
}