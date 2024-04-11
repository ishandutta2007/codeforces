#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  set<int> se;
  while (n--) {
    int a;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
    }
    while (a % 3 == 0) {
      a /= 3;
    }
    se.insert(a);
  }
  cout << (size(se) == 1 ? "Yes\n" : "No\n");
}