#include <bits/stdc++.h>
using namespace std;

int _gcd(int a, int b) {
  if (a == 0) return b;
  return _gcd(b % a, a);

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n;
  cin >> k;

  int ans = k;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    ans = _gcd(ans, x);
  }

  vector<int> v;

  for(int i = 0; i < k; ++i) {
    if (i % ans == 0) {
      v.push_back(i);
    }
  }

  cout << v.size() << "\n";
  for(int i: v) {
    cout << i << " ";
  }
  cout << "\n";
}