#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  int m = (n << 1) - 1;
  vector<int> a(m);
  int first = -1;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    if (!~first && ~a[i]) {
      first = i;
    }
  }
  if (!~first) {
    puts("yes");
    printf("1");
    for (int i = 1; i < n; ++i) {
      printf(" %d 1", i + 1);
    }
    putchar(10);
    return 0;
  }
  if (first) {
    vector<int> temp;
    for (int i = first; i < m; ++i) {
      temp.push_back(a[i]);
    }
    for (int i = 0; i < first; ++i) {
      temp.push_back(a[i]);
    }
    a = temp;
  }

  if (~a.back() && a.back() != a[0]) {
    puts("no");
    return 0;
  }
  a.back() = a[0];
  vector<int> free, parity(n, -1);
  for (int i = 0; i < m; ++i) {
    if (~a[i]) {
      if (~parity[a[i]]) {
        if (parity[a[i]] != (i & 1)) {
          puts("no");
          return 0;
        }
      } else {
        parity[a[i]] = i & 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!~parity[i]) {
      free.push_back(i);
    }
  }

  vector<int> prev(m), next(m);
  for (int i = 0; i < m; ++i) {
    prev[i] = i - 1;
    next[i] = i + 1;
  }

  auto erase = [&](int x) {
    if (next[x] != m) {
      prev[next[x]] = prev[x];
    }
    if (~prev[x]) {
      next[prev[x]] = next[x];
    }
  };

  auto solve = [&](int l, int r) {
    for (int i = next[l]; i < r; ) {
      if (~a[i] && ~a[next[i]] && !~a[prev[i]]) {
        a[prev[i]] = a[next[i]];
        erase(i);
        erase(next[i]);
        i = prev[i];
        if (i > l) {
          i = prev[i];
        }
        if (i == l) {
          i = next[i];
        }
      } else if (~a[i] && ~a[prev[i]] && !~a[next[i]]) {
        a[next[i]] = a[prev[i]];
        erase(i);
        erase(next[i]);
        i = prev[i];
        if (i == l) {
          i = next[i];
        }
      } else {
        i = next[i];
      }
    }
    for (int i = next[l]; i < r; i = next[i]) {
      erase(i);
    }
    erase(r);
  };

  vector<bool> not_first(n), ban(n);
  for (int i = 0; i < m; ++i) {
    if (~a[i]) {
      if (not_first[a[i]]) {
        if (ban[a[i]]) {
          puts("no");
          return 0;
        }
        int left = prev[i], right = i, numbers = 1, total = 1;
        while (a[left] != a[right]) {
          if (~a[left]) {
            ban[a[left]] = true;
            ++numbers;
          }
          ++total;
          left = prev[left];
        }
        int need = (total >> 1) + 1 - numbers;
        if (need < 0) {
          puts("no");
          return 0;
        }
        for (int j = left; j < right; j = next[j]) {
          if (!~a[j] && need) {
            if (free.empty()) {
              puts("no");
              return 0;
            } else {
              a[j] = free.back();
              --need;
              free.pop_back();
            }
          }
        }
        solve(left, right);
      } else {
        not_first[a[i]] = true;
      }
    }
  }

  puts("yes");
  if (first) {
    vector<int> temp;
    for (int i = m - 1 - first; i < m - 1; ++i) {
      temp.push_back(a[i]);
    }
    for (int i = 0; i < m - 1 - first; ++i) {
      temp.push_back(a[i]);
    }
    temp.push_back(a[m - 1 - first]);
    a = temp;
  }
  for (int i = 0; i < m; ++i) {
    printf("%d%c", a[i] + 1, i == m - 1 ? '\n' : ' ');
  }
  return 0;
}