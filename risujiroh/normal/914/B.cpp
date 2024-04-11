#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  set<int> se;
  while (n--) {
    int a;
    cin >> a;
    if (se.count(a))
      se.erase(a);
    else
      se.insert(a);
  }
  cout << (empty(se) ? "Agasa\n" : "Conan\n");
}