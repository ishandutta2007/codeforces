#include <bits/stdc++.h>

using namespace std;

const int MAX = 200;
const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> f(MAX + 1, 1), g(MAX + 1, 0);
  for (int i = 0; i < n; ++i) {
    int value;
    cin >> value;
    vector<int> tf(MAX + 1, 0), tg(MAX + 1, 0);
    for (int j = (~value ? value : 1); j <= (~value ? value : MAX); ++j) {
      add(tf[j], f[j - 1]);
      add(tf[j], g[j - 1]);
      add(tg[j], f[j]);
      sub(tg[j], f[j - 1]);
      add(tg[j], g[MAX]);
      sub(tg[j], g[j - 1]);
    }
    for (int j = 1; j <= MAX; ++j) {
      add(tf[j], tf[j - 1]);
      add(tg[j], tg[j - 1]);
    }
    f = tf;
    g = tg;
  }
  cout << g[MAX] << endl;
  return 0;
}