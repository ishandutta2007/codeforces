#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for(auto &x : v)
      cin >> x;
    sort(v.begin(), v.end());
    for(int i = 0; i < 2 * n; i++) {
      cout << v[(i % 2) * n + i / 2] << " ";
    }
    cout << '\n';
  }
}