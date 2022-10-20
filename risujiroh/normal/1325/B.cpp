#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    set<int> se;
    while (n--) {
      int a;
      cin >> a;
      se.insert(a);
    }
    cout << se.size() << '\n';
  }
}