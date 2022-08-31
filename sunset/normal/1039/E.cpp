#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  int log_n = 0;
  while (1 << log_n <= n) {
    ++log_n;
  }
  int jump_small = pow(n, 1.0 / 3), jump_large = pow(n, 2.0 / 3);
  
  vector<vector<int>> rmq_min(log_n, vector<int> (n)), rmq_max(log_n, vector<int> (n));
  vector<int> a(n), next(n), jump(n), times(n), now_min(n), now_max(n);
  priority_queue<pair<int, int>> heap;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    rmq_min[0][i] = rmq_max[0][i] = a[i];
    next[i] = i + 1;
    jump[i] = min(i + jump_small, n);
    times[i] = jump[i] - i;
  }
  for (int i = 0; i < n - 1; ++i) {
    now_min[i] = min(a[i], a[i + 1]);
    now_max[i] = max(a[i], a[i + 1]);
    heap.push(make_pair(now_min[i] - now_max[i], i));
  }
  for (int i = 1; i < log_n; ++i) {
    for (int j = 0; j + (1 << i) <= n; ++j) {
      rmq_min[i][j] = min(rmq_min[i - 1][j], rmq_min[i - 1][j + (1 << i - 1)]);
      rmq_max[i][j] = max(rmq_max[i - 1][j], rmq_max[i - 1][j + (1 << i - 1)]);
    }
  }

  vector<int> last(n);
  vector<bool> visit(n);
  auto update = [&](int x, int limit) {
    while (next[x] < n && next[x] - x <= jump_large && now_max[x] - now_min[x] <= limit) { 
      ++next[x];
      if (next[x] < n) {
        now_max[x] = max(now_max[x], a[next[x]]);
        now_min[x] = min(now_min[x], a[next[x]]);
      }
    }
    if (next[x] < n && next[x] - x <= jump_small) {
      heap.push(make_pair(now_min[x] - now_max[x], x));
    }

    vector<int> stack;
    jump[x] = x;
    times[x] = 0;
    stack.push_back(jump[x]);
    while (jump[x] < n && next[jump[x]] - x <= jump_small) {
      jump[x] = next[jump[x]];
      ++times[x];
      stack.push_back(jump[x]);
    }

    last[x] = stack.size();
    visit[x] = true;
    for (int i = x - 1; i >= x - jump_small && ~i; --i) {
      if (next[i] < n && visit[next[i]]) {
        while (stack.back() - i > jump_small) {
          stack.pop_back();
        }
        jump[i] = stack.back();
        times[i] = times[next[i]] + 1 + stack.size() - last[next[i]];
        last[i] = stack.size();
        visit[i] = true;
      }
    }
    for (int i = x; i >= x - jump_small && ~i; --i) {
      visit[i] = false;
    }
  };

  auto query = [&](int limit) {
    while (!heap.empty() && -heap.top().first <= limit) {
      int x = heap.top().second;
      heap.pop();
      update(x, limit);
    }
    int answer = -1, x = 0;
    while (x < n) {
      int dist = next[x] - x;
      if (dist <= jump_small) {
        answer += times[x];
        x = jump[x];
      } else {
        while (next[x] < n && next[x] - x <= jump_large && now_max[x] - now_min[x] <= limit) {
          ++next[x];
          if (next[x] < n) {
            now_max[x] = max(now_max[x], a[next[x]]);
            now_min[x] = min(now_min[x], a[next[x]]);
          }
        }
        dist = next[x] - x;
        if (dist <= jump_large) {
          ++answer;
          x = next[x];
        } else {
          ++answer;
          int current_min = a[x], current_max = a[x];
          for (int i = log_n - 1; ~i; --i) {
            if (x + (1 << i) <= n) {
              int next_min = min(current_min, rmq_min[i][x]);
              int next_max = max(current_max, rmq_max[i][x]);
              if (next_max - next_min <= limit) {
                current_min = next_min;
                current_max = next_max;
                x += 1 << i;
              }
            }
          }
        }
      }
    }
    return answer;
  };

  vector<pair<int, int>> queries(q);
  vector<int> answer(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &queries[i].first);
    queries[i].first = m - queries[i].first;
    queries[i].second = i;
  }
  sort(queries.begin(), queries.end());
  for (auto p : queries) {
    answer[p.second] = query(p.first);
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", answer[i]);
  }
  return 0;
}