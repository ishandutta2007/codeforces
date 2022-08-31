#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> value(n), l(n, -1), r(n, -1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &value[i]);
      if (!~value[i]) {
        scanf("%d %d", &l[i], &r[i]);
      }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    vector<int> size(n);

    auto merge = [&](int x, int y, bool who) {
      if (who) {
        return min(x, y);
      } else {
        return max(x, y);
      }
    };

    function<void(int)> init = [&](int x) {
      if (!~value[x]) {
        init(l[x]);
        init(r[x]);
        size[x] = size[l[x]] + size[r[x]] + 1;
        if (size[r[x]] & 1) {
          swap(l[x], r[x]);
        }
      }
    };

    function<int(int, bool, int)> dfs = [&](int x, bool who, int skip) {
      if (~value[x]) {
        return value[x];
      } else if (size[x] == 1) {
        return merge(value[l[x]], value[r[x]], who ^ (skip == 2));
      } else if (~dp[x][who][skip]) {
        return dp[x][who][skip];
      } else {
        int &result = dp[x][who][skip];
        if (skip) {
          result = dfs(x, !who, 0);
          if (size[x] & 1) {
            if (size[l[x]] & 1) {
              result = merge(result, merge(dfs(l[x], who, 0), dfs(r[x], !who, 1 + (size[l[x]] == 1 && skip == 1)), !who), who);
              result = merge(result, merge(dfs(r[x], who, 0), dfs(l[x], !who, 1 + (size[r[x]] == 1 && skip == 1)), !who), who);
            } else {
              if (size[l[x]]) {
                result = merge(result, merge(dfs(r[x], !who, 0), dfs(l[x], who, 1 + (size[r[x]] == 0 && skip == 1)), !who), who);
              }
              if (size[r[x]]) {
                result = merge(result, merge(dfs(l[x], !who, 0), dfs(r[x], who, 1 + (size[l[x]] == 0 && skip == 1)), !who), who);
              }
            }
          } else {
            result = merge(result, merge(dfs(r[x], who, 0), dfs(l[x], who, 1 + (size[r[x]] == 0 && skip == 1)), who), who);
          }
        } else {
          if (size[x] & 1) {
            if (size[l[x]] & 1) {
              result = merge(dfs(l[x], who, 1), dfs(r[x], who, 1), who);
            } else {
              result = merge(dfs(l[x], who, 0), dfs(r[x], who, 0), who);
            }
          } else {
            result = merge(merge(dfs(l[x], who, 0), dfs(r[x], !who, 0), !who), merge(dfs(r[x], who, 1), dfs(l[x], !who, 1), !who), who);
          }
        }
        return result;
      }
    };
  
    init(0);
    printf("%d\n", dfs(0, 0, 0));
  }
  return 0;
}