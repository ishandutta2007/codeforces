#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;

    bool wins;

    if (n & 1) {
      wins = true;
    } else {
      wins = (min_element(begin(a), end(a)) - begin(a)) & 1;
    }

    cout << (wins ? "Mike\n" : "Joe\n");
  }
}