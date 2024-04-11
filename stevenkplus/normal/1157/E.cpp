// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

void fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
}

// =========== Solution ============= //

int main()  {
  fastio();
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b.insert(x);
    b.insert(x - n);
  }
  for (int i = 0; i < n; ++i) {
    int x = *b.lower_bound(-a[i]);
    if (x < 0) x += n;
    b.erase(b.find(x));
    b.erase(b.find(x - n));
    cout << (x + a[i]) % n << " ";
  }
  cout << "\n";
}