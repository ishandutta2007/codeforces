#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> s(n), length(n), t(n), by_s(n), by_t(n), by(n), day(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &s[i], &length[i], &t[i]);
    by_s[i] = by_t[i] = i;
  }
  vector<int> f(1 << n, inf);
  vector<pair<int, int>> from(1 << n);
  f[0] = 1;
  sort(by_s.begin(), by_s.end(), [&](const int &x, const int &y) {
    return s[x] < s[y];
  });
  sort(by_t.begin(), by_t.end(), [&](const int &x, const int &y) {
    return t[x] < t[y];
  });
  for (int i = 0; i < 1 << n; ++i) {
    if (f[i] != inf) {
      int pointer = 0, value = f[i];
      for (auto j : by_t) {
        if (!(i >> j & 1)) {
          while (pointer < n && value + t[j] >= s[by_s[pointer]]) {
            int p = by_s[pointer++];
            if ((i >> p & 1) || value >= s[p]) {
              value = max(value, s[p] + length[p]);
            }
          }
          if (value + t[j] < s[j] && f[i | 1 << j] > value + t[j]) {
            f[i | 1 << j] = value + t[j];
            from[i | 1 << j] = make_pair(j, value);
          }
        }
      }
    }
  }
  function<void(int, int)> rec = [&](int x, int type) {
    if (!x) {
      return;
    }
    int i = from[x].first;
    by[i] = type;
    day[i] = from[x].second;
    rec(x ^ 1 << i, type);
  };
  if (m == 1) {
    if (f[(1 << n) - 1] != inf) {
      puts("YES");
      rec((1 << n) - 1, 1);
      for (int i = 0; i < n; ++i) {
        printf("%d %d\n", by[i], day[i]);
      }
    } else {
      puts("NO");
    }
  } else {
    int p = -1;
    for (int i = 0; i < (1 << n); ++i) {
      if (f[i] != inf && f[(1 << n) - 1 ^ i] != inf) {
        p = i;
        break;
      }
    }
    if (!~p) {
      puts("NO");
    } else {
      puts("YES");
      rec(p, 1);
      rec((1 << n) - 1 ^ p, 2);
      for (int i = 0; i < n; ++i) {
        printf("%d %d\n", by[i], day[i]);
      }
    }
  }
  return 0;
}