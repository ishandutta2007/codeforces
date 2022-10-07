#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1111;
int a[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll prod = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int k = abs(a[i] - a[j]);
      prod = prod * k % m;
    }
  }
  cout << prod << "\n";
}