#include <bits/stdc++.h>
using namespace std;

double go(double rocket, int rate) {
  if (rocket == -1) return -1;
  if (rate <= 1) return -1;
  return rocket * (1 + 1.0 / (rate - 1));
}

int n, m;
int guess(int x) {
  if (x > m) x = m;
  cout << x << endl;
  int r;
  cin >> r;
  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    int r = guess(1);
    if (r == 0) return 0;
    a[i] = r;
  }

  int add = 1 << 29;
  int cur = 0;
  for(int i = 0; i < 30; ++i) {
    int r = guess(cur + add);
    r *= a[i % n];
    if (r == 0) return 0;
    if (r == 1) cur += add;
    add /= 2;
  }
}