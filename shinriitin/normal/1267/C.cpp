#include <bits/stdc++.h>

using PII = std::pair<int, int>;

using std::vector;

vector<PII> ans;

void fail() {
  puts("-1");
  exit(0);
}

void solve(vector<PII>&&cur) {
  std::sort(cur.begin(), cur.end());
  if (cur.empty()) {
    return;
  }
  if (cur.size() == 1 || cur[0].first > 2) {
    fail();
  }
  vector<PII> next;
  if (cur[0].first == 1) {
    if (cur.back().first == 1) {
      if (cur.size() > 2) {
        fail();
      }
      ans.emplace_back(cur[0].second, cur[1].second);
      return;
    }
    int pos = cur.size() - 1;
    for (int j = pos; j; --j) {
      if (cur[j].first % 2 == 1 && cur[j].first > 1) {
        pos = j;
        break;
      }
    }
    --cur[pos].first;
    ans.emplace_back(cur[0].second, cur[pos].second);
    std::swap(cur[0], cur.back());
    cur.pop_back();
  } else {
    if (cur.back().first == 2) {
      if (cur.size() == 2) {
        fail();
      }
      for (int i = 0; i < cur.size(); ++i) {
        int u = cur[i].second;
        int v = i ? cur[i - 1].second : cur.back().second;
        ans.emplace_back(u, v);
      }
      return;
    }
    if (cur[1].first > 2) {
      fail();
    }
    int u = cur[0].second;
    int v = cur[1].second;
    int w = cur.back().second;
    ans.emplace_back(u, v);
    ans.emplace_back(u, w);
    ans.emplace_back(v, w);
    cur.back().first -= 2;
    std::swap(cur[0], cur.back());
    cur.pop_back();
    std::swap(cur[1], cur.back());
    cur.pop_back();
  }
  solve(std::move(cur));
}

int main() {
  int n;
  scanf("%d", &n);
  vector<PII> vec;
  for (int i = 1, d; i <= n; ++i) {
    scanf("%d", &d);
    vec.emplace_back(d, i);
  }
  solve(std::move(vec));
  int m = ans.size();
  printf("%d\n", m);
  for (const auto& pr : ans) {
    printf("2 %d %d\n", pr.first, pr.second);
  }
}