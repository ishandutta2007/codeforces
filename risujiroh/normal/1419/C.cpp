#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    if (count(begin(a), end(a), x) == n) {
      cout << "0\n";
    } else if (find(begin(a), end(a), x) != end(a) or
               accumulate(begin(a), end(a), 0) == n * x) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}