#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  if (p[0]) {
    puts("No");
    return 0;
  }
  vector<bool> visit(n, false);
  for (int i = 0, j = 1; i < n; ++i) {
    int x = p[i];
    visit[x] = true;
    vector<int> a, b;
    for (auto y : adj[x]) {
      if (!visit[y]) {
        a.push_back(y);
      }
    }
    for (int k = 0; k < a.size(); ++k) {
      b.push_back(p[j + k]);
    }
    j += a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int k = 0; k < a.size(); ++k) {
      if (a[k] != b[k]) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}