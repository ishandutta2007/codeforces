#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, m, s;
  cin >> h >> m >> s;
  if (h == 12) h = 0;
  array<double, 3> a;
  a[0] = s / double(60);
  a[1] = (s + 60 * m) / double(60 * 60);
  a[2] = (s + 60 * (m + 60 * h)) / double(60 * 60 * 12);
  sort(begin(a), end(a));
  auto where = [&](double x) -> int {
    if (a[0] < x && x < a[1]) return 0;
    if (a[1] < x && x < a[2]) return 1;
    if (x < a[0] || a[2] < x) return 2;
    assert(false);
  };
  int t1, t2;
  cin >> t1 >> t2;
  if (t1 == 12) t1 = 0;
  if (t2 == 12) t2 = 0;
  cout << (where(t1 / double(12)) == where(t2 / double(12)) ? "YES\n" : "NO\n");
}