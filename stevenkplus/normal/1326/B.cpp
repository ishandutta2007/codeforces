#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int m = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    x += m;
    m = max(m, x);
    cout << x << " ";
  }
  cout << "\n";
}