#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  int m, n; cin >> m >> n;
  VI p(n);
  for (int i = 0; i < n; i++) {
    cout << m << endl;
    int a; cin >> a;
    if (a == 0) return 0;
    p[i] = a == -1 ? 1 : 0;
  }
  int i = 0, l = 1, r = m;
  while (true) {
    int c = (l + r) / 2;
    cout << c << endl;
    int a; cin >> a;
    if (a == 0) return 0;
    if (p[i % n] == 0) a *= -1;
    if (a == -1) r = c;
    else l = c;
    i++;
  }
  return 0;
}