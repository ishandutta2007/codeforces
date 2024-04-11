#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m, f[N], to[N];
pair<int, int> a[N];
bool done[N];

int find(int x) {
  while (x != f[x]) {
    x = f[x] = f[f[x]];
  }
  return x;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; i = j) {
    while (j <= n && a[j].first == a[i].first) {
      ++j;
    }
    for (int k = i; k < j; ++k) {
      if (a[k].second >= i && a[k].second < j) {
        to[a[k].second] = a[k].second;
        done[a[k].second] = true;
        ++m;
      }
    }
    int t = i;
    for (int k = i; k < j; ++k) {
      if (a[k].second < i || a[k].second >= j) {
        while (done[t]) {
          ++t;
        }
        to[a[k].second] = t++;
      }
    }
  }
  if (m < n) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    f[find(i)] = find(to[i]);
  }
  for (int i = 1, j = 1; i <= n; i = j) {
    while (j <= n && a[j].first == a[i].first) {
      ++j;
    }
    int last = 0;
    for (int k = i; k < j; ++k) {
      if (!done[a[k].second]) {
        int t = a[k].second;
        if (last && find(last) != find(t)) {
          f[find(last)] = find(t);
          swap(to[last], to[a[k].second]);
        }
        last = a[k].second;
      }
    }
  }
  int cycle = 0;
  for (int i = 1; i <= n; ++i) {
    if (find(i) == i && to[i] != i) {
      ++cycle;
    }
  }
  int change = min(cycle, m - n);
  vector<int> all, go;
  if (change > 2) {
    for (int i = 1; i <= n; ++i) {
      if (find(i) == i && to[i] != i) {
        all.push_back(i);
        go.push_back(to[i]);
        if (all.size() == change) {
          break;
        }
      }
    }
    for (int i = 0; i < change; ++i) {
      to[all[i]] = go[(i + change - 1) % change];
      if (i) {
        f[find(all[i])] = find(all[i - 1]);
      }
    }
  }
  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    if (find(i) == i && to[i] != i) {
      ++answer;
    }
  }
  printf("%d\n", answer + (!go.empty()));
  for (int i = 1; i <= n; ++i) {
    if (find(i) == i && to[i] != i) {
      vector<int> a;
      a.push_back(i);
      for (int x = to[i]; x != i; x = to[x]) {
        a.push_back(x);
      }
      printf("%d\n", a.size());
      for (int j = 0; j < a.size(); ++j) {
        printf("%d%c", a[j], j == a.size() - 1 ? '\n' : ' ');
      }
    }
  }
  if (!go.empty()) {
    printf("%d\n", go.size());
    for (int i = 0; i < go.size(); ++i) {
      printf("%d%c", go[i], i == go.size() - 1 ? '\n' : ' ');
    }
  }
  return 0;
}