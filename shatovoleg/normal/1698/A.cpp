#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  int n;
  cin >> n;
  while (n --> 0) {
    solve();
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  cout << a[0] << endl;
}