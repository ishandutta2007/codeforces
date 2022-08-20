#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

pair<int, int> operator + (const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

pair<int, int> operator - (const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first - b.first, a.second - b.second);
}

pair<int, int> rotate(pair<int, int> a) {
  return make_pair(a.y, -a.x);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> answer;
  vector<vector<int>> board(n, vector<int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &board[i][j]);
    }
  }
  auto in = [&](pair<int, int> a) {
    return a.x >= 0 && a.x < n && a.y >= 0 && a.y < m;
  };
  auto make = [&](vector<pair<int, int>> v) {
    answer.push_back(vector<int> ());
    for (auto p : v) {
      answer.back().push_back(board[p.x][p.y]);
    }
    int temp = board[v.back().x][v.back().y];
    for (int i = v.size() - 1; i; --i) {
      board[v[i].x][v[i].y] = board[v[i - 1].x][v[i - 1].y];
    }
    board[v[0].x][v[0].y] = temp;
  };
  auto make_swap = [&](pair<int, int> a, pair<int, int> b, pair<int, int> d) {
    pair<int, int> c = b + b - a;
    pair<int, int> e = b + d - a;
    pair<int, int> f = c + d - a;
    make({a, b, e, d});
    make({b, c, f, e});
    make({d, e, f, c, b, a});
  };
  auto my_swap = [&](pair<int, int> a, pair<int, int> b) {
    pair<int, int> c = b + b - a;
    if (!in(c)) {
      swap(a, b);
    }
    pair<int, int> v = rotate(a - b);
    pair<int, int> d = a + v;
    if (!in(d)) {
      d = a - v;
    }
    make_swap(a, b, d);
  };
  for (int i = 0; i < n * m; ++i) {
    pair<int, int> to = make_pair(i / m, i % m);
    pair<int, int> from;
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < m; ++y) {
        if (board[x][y] == i + 1) {
          from = make_pair(x, y);
        }
      }
    }
    while (from.y < to.y) {
      if (from.x + 1 < n) {
        make({from, from + make_pair(0, 1), from + make_pair(1, 1), from + make_pair(1, 0)});
      } else if (from.x - 1 > to.x) {
        make({from, from + make_pair(0, 1), from + make_pair(-1, 1), from + make_pair(-1, 0)});
      } else {
        my_swap(from, from + make_pair(0, 1));
      }
      ++from.y;
    }
    while (from.y > to.y) {
      if (from.x + 1 < n) {
        make({from, from + make_pair(0, -1), from + make_pair(1, -1), from + make_pair(1, 0)});
      } else if (from.x - 1 > to.x) {
        make({from, from + make_pair(0, -1), from + make_pair(-1, -1), from + make_pair(-1, 0)});
      } else {
        my_swap(from, from + make_pair(0, -1));
      }
      --from.y;
    }
    while (from.x > to.x) {
      if (from.y + 1 < m) {
        make({from, from + make_pair(-1, 0), from + make_pair(-1, 1), from + make_pair(0, 1)});
      } else {
        my_swap(from, from + make_pair(-1, 0));
      }
      --from.x;
    }
  }
  printf("%d\n", answer.size());
  for (auto p : answer) {
    printf("%d", p.size());
    for (auto x : p) {
      printf(" %d", x);
    }
    putchar(10);
  }
  return 0;
}