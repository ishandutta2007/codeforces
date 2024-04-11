#include <bits/stdc++.h>

using namespace std;

struct info_t {
  int x, y, i;
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<info_t> from(m), to(m);
  vector<vector<int>> answer_from, answer_to;
  auto solve = [&](vector<info_t> &info, vector<vector<int>> &answer) {
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", &info[i].x, &info[i].y);
      --info[i].x;
      --info[i].y;
      info[i].i = i;
    }
    sort(info.begin(), info.end(), [&](const info_t &a, const info_t &b) {
      return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    while (true) {
      bool need = false;
      for (int i = 0; i < m; ++i) {
        if (info[i].x > i) {
          answer.push_back(vector<int> {info[i].x, info[i].y, info[i].x - 1, info[i].y});
          --info[i].x;
          need = true;
        }
      }
      for (int i = m - 1; ~i; --i) {
        if (info[i].x < i) {
          answer.push_back(vector<int> {info[i].x, info[i].y, info[i].x + 1, info[i].y});
          ++info[i].x;
          need = true;
        }
      }
      if (!need) {
        break;
      }
    }
    for (int i = 0; i < m; ++i) {
      while (info[i].y < info[i].i) {
        answer.push_back(vector<int> {info[i].x, info[i].y, info[i].x, info[i].y + 1});
        ++info[i].y;
      }
      while (info[i].y > info[i].i) {
        answer.push_back(vector<int> {info[i].x, info[i].y, info[i].x, info[i].y - 1});
        --info[i].y;
      }
    }
  };
  solve(from, answer_from);
  solve(to, answer_to);
  sort(from.begin(), from.end(), [&](const info_t &a, const info_t &b) {
    return a.i < b.i;
  });
  sort(to.begin(), to.end(), [&](const info_t &a, const info_t &b) {
    return a.i < b.i;
  });
  for (int i = 0; i < m; ++i) {
    while (from[i].x < to[i].x) {
      answer_from.push_back(vector<int> {from[i].x, from[i].y, from[i].x + 1, from[i].y});
      ++from[i].x;
    }
    while (from[i].x > to[i].x) {
      answer_from.push_back(vector<int> {from[i].x, from[i].y, from[i].x - 1, from[i].y});
      --from[i].x;
    }
  }
  printf("%d\n", answer_from.size() + answer_to.size());
  for (auto v : answer_from) {
    printf("%d %d %d %d\n", v[0] + 1, v[1] + 1, v[2] + 1, v[3] + 1);
  }
  reverse(answer_to.begin(), answer_to.end());
  for (auto v : answer_to) {
    printf("%d %d %d %d\n", v[2] + 1, v[3] + 1, v[0] + 1, v[1] + 1);
  }
  return 0;
}