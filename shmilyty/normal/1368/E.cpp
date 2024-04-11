#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<set<int>> to(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      to[v - 1].insert(u - 1);
    }
    vector<int> color(n);
    for (int i = 0; i < n; ++i) {
      for (int u : to[i]) {
        if (color[u] == 1)
          color[i] = 2;
        if (color[i] != 2 && color[u] == 0)
          color[i] = 1;
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (color[i] == 2)
        ans.emplace_back(i + 1);
    printf("%d\n", (int)ans.size());
    for (int i : ans)
      printf("%d ", i);
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}