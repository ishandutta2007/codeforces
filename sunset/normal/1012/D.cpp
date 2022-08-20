#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

pair<int, int> a[N], b[N];
char s[N], t[N];
int n, m;

void make(char *s, pair<int, int> *a, int &n) {
  for (int i = 1; s[i]; ++i) {
    if (!n || s[i] - 'a' != a[n].first) {
      a[++n].first = s[i] - 'a';
    }
    ++a[n].second;
  }
}

vector<pair<int, int>> greedy(pair<int, int> *a, int n, pair<int, int> *b, int m) {
  while (n && !a[n].first) {
    --n;
  }
  while (m && b[m].first == 1) {
    --m;
  }
  int x = 0, y = 0;
  for (int i = 1; i <= n; ++i) {
    x += a[i].second;
  }
  for (int i = 1; i <= m; ++i) {
    y += b[i].second;
  }
  vector<pair<int, int>> result;
  for (int i = 1; i <= max(n, m); ++i) {
    if (i & 1) {
      result.push_back(make_pair(x, y));
    } else {
      result.push_back(make_pair(y, x));
    }
    if (i <= n) {
      x -= a[n - i + 1].second;
    }
    if (i <= m) {
      y -= b[m - i + 1].second;
    }
  }
  return result;
}

void extend(pair<int, int> *a, int &n, pair<int, int> p) {
  if (n && a[n].first == p.first) {
    a[n].second += p.second;
  } else {
    a[++n] = p;
  }
}

vector<pair<int, int>> solve(pair<int, int> *a, int n, pair<int, int> *b, int m) {
  if (a[n].first == 0) {
    --n;
  }
  if (b[m].first == 1) {
    --m;
  }
  vector<pair<int, int>> result = greedy(a, n, b, m);
  static pair<int, int> c[N], d[N];
  if (n < m) {
    for (int i = max((m - n >> 1) - 2, 1); i <= min((m - n >> 1) + 2, m); ++i) {
      for (int j = 0; j < 2 && j <= n; ++j) {
        int p = 0, q = 0;
        for (int x = 1; x <= i; ++x) {
          extend(c, p, b[x]);
        }
        for (int x = j + 1; x <= n; ++x) {
          extend(c, p, a[x]);
        }
        for (int x = 1; x <= j; ++x) {
          extend(d, q, a[x]);
        }
        for (int x = i + 1; x <= m; ++x) {
          extend(d, q, b[x]);
        }
        vector<pair<int, int>> temp = greedy(c, p, d, q);
        if (result.size() > temp.size() + 1) {
          result.clear();
          int u = 0, v = 0;
          for (int x = 1; x <= j; ++x) {
            u += a[x].second;
          }
          for (int x = 1; x <= i; ++x) {
            v += b[x].second;
          }
          result.push_back(make_pair(u, v));
          for (auto t : temp) {
            result.push_back(t);
          }
        }
      }
    }
  } else if (n > m) {
    for (int i = max((n - m >> 1) - 2, 1); i <= min((n - m >> 1) + 2, n); ++i) {
      for (int j = 0; j < 2 && j <= m; ++j) {
        int p = 0, q = 0;
        for (int x = 1; x <= i; ++x) {
          extend(d, q, a[x]);
        }
        for (int x = j + 1; x <= m; ++x) {
          extend(d, q, b[x]);
        }
        for (int x = 1; x <= j; ++x) {
          extend(c, p, b[x]);
        }
        for (int x = i + 1; x <= n; ++x) {
          extend(c, p, a[x]);
        }
        vector<pair<int, int>> temp = greedy(c, p, d, q);
        if (result.size() > temp.size() + 1) {
          result.clear();
          int u = 0, v = 0;
          for (int x = 1; x <= i; ++x) {
            u += a[x].second;
          }
          for (int x = 1; x <= j; ++x) {
            v += b[x].second;
          }
          result.push_back(make_pair(u, v));
          for (auto t : temp) {
            result.push_back(t);
          }
        }
      }
    }
  }
  return result;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%s %s", s + 1, t + 1);
  make(s, a, n);
  make(t, b, m);
  vector<pair<int, int>> u = solve(a, n, b, m), v = solve(b, m, a, n);
  if (u.size() > v.size()) {
    u = v;
    for (int i = 0; i < u.size(); ++i) {
      swap(u[i].first, u[i].second);
    }
  }
  printf("%d\n", u.size());
  for (auto p : u) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}