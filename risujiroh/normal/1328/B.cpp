#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    k = n * (n - 1) / 2 - k;
    string s(n, 'a');
    for (int i = 0; i < n; ++i) {
      if (k < n - 1 - i) {
        s[i] = s[i + k + 1] = 'b';
        break;
      }
      k -= n - 1 - i;
    }
    // reverse(begin(s), end(s));
    cout << s << '\n';
  }
}