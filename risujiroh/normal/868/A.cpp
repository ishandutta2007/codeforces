#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  char a, b;
  cin >> a >> b;
  bool f = false, g = false;
  int n;
  cin >> n;
  while (n--) {
    char c, d;
    cin >> c >> d;
    f |= a == d;
    g |= b == c;
    if (a == c && b == d) f = g = true;
  }
  cout << (f && g ? "YES\n" : "NO\n");
}