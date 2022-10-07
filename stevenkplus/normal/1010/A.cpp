#include <bits/stdc++.h>
using namespace std;

double go(double rocket, int rate) {
  if (rocket == -1) return -1;
  if (rate <= 1) return -1;
  return rocket * (1 + 1.0 / (rate - 1));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  cin >> m;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  double f = m;
  for(int i = n - 1; i >= 0; --i) {
    f = go(f, b[(i + 1) % n]);
    f = go(f, a[i]);
  }
  if (f != -1) {
    f -= m;
    cout << fixed << setprecision(10) << f << "\n";
  } else {
    cout << "-1\n";
  }
}