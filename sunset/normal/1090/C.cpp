#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n);
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    for (int j = 0; j < s; ++j) {
      int x;
      scanf("%d", &x);
      a[i].push_back(x - 1);
    }
    total += s;
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&](int x, int y) {
    return a[x].size() > a[y].size();
  });
  vector<int> need(n);
  for (int i = 0; i < n; ++i) {
    need[i] = total / n + (i < total % n);
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    if (a[p[i]].size() > need[i]) {
      answer += a[p[i]].size() - need[i];
    }
  }
  printf("%d\n", answer);
  vector<bool> ban(m);
  for (int i = 0, j = n - 1; i < j; ) {
    while (i < j && a[p[i]].size() == need[i]) {
      ++i;
    }
    while (i < j && a[p[j]].size() == need[j]) {
      --j;
    }
    if (i >= j) {
      break;
    }
    int c = min(a[p[i]].size() - need[i], need[j] - a[p[j]].size());
    for (auto x : a[p[j]]) {
      ban[x] = true;
    }
    vector<int> temp;
    while (c--) {
      while (ban[a[p[i]].back()]) {
        temp.push_back(a[p[i]].back());
        a[p[i]].pop_back();
      }
      printf("%d %d %d\n", p[i] + 1, p[j] + 1, a[p[i]].back() + 1);
      a[p[j]].push_back(a[p[i]].back());
      a[p[i]].pop_back();
    }
    for (auto x : temp) {
      a[p[i]].push_back(x);
    }
    for (auto x : a[p[j]]) {
      ban[x] = false;
    }
  }
  return 0;
}