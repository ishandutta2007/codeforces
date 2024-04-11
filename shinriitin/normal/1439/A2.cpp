#include <bits/stdc++.h>

class Solver {
 public:
  Solver() {
    scanf("%d%d", &n_, &m_);
    grid_.reserve(n_);
    for (int i = 0; i < n_; ++i) {
      std::string str;
      std::cin >> str;
      grid_.emplace_back(str);
    }
  }

  void Solve() {
    for (int x = n_ - 1; x >= 2; --x) {
      for (int y = 0; y + 1 < m_; ++y) {
        if (grid_[x][y] == '0') {
          continue;
        }
        ans_.emplace_back(x + 1, y + 1, x, y + 1, x, y + 2);
        Flip(x, y);
        Flip(x - 1, y);
        Flip(x - 1, y + 1);
      }
      if (grid_[x][m_ - 1] == '1') {
        ans_.emplace_back(x + 1, m_, x, m_ - 1, x, m_);
        Flip(x, m_ - 1);
        Flip(x - 1, m_ - 1);
        Flip(x - 1, m_ - 2);
      }
    }
    for (int y = m_ - 1; y >= 2; --y) {
      if (grid_[0][y] == '1') {
        ans_.emplace_back(1, y + 1, 1, y, 2, y);
        Flip(0, y);
        Flip(0, y - 1);
        Flip(1, y - 1);
      }
      if (grid_[1][y] == '1') {
        ans_.emplace_back(2, y + 1, 1, y, 2, y);
        Flip(1, y);
        Flip(0, y - 1);
        Flip(1, y - 1);
      }
    }
    SolveSubGrid(0, 0);
    printf("%d\n", static_cast<int>(ans_.size()));
    for (const auto &item : ans_) {
      printf("%d %d %d %d %d %d\n",
             std::get<0>(item),
             std::get<1>(item),
             std::get<2>(item),
             std::get<3>(item),
             std::get<4>(item),
             std::get<5>(item));
    }
  }

 private:
  void Flip(int x, int y) {
    if (grid_[x][y] == '0') {
      grid_[x][y] = '1';
    } else {
      grid_[x][y] = '0';
    }
  }

  void SolveSubGrid(int x, int y) {
    std::vector<std::pair<int, int>> black;
    std::vector<std::pair<int, int>> white;
    for (int dx = 0; dx < 2; ++dx) {
      for (int dy = 0; dy < 2; ++dy) {
        if (grid_[x + dx][y + dy] == '1') {
          black.emplace_back(x + dx + 1, y + dy + 1);
        } else {
          white.emplace_back(x + dx + 1, y + dy + 1);
        }
        grid_[x + dx][y + dy] = '0';
      }
    }
    switch (black.size()) {
      case 1: {
        for (int i = 0; i < 3; ++i) {
          ans_.emplace_back(black[0].first,
                            black[0].second,
                            white[i].first,
                            white[i].second,
                            white[(i + 1) % 3].first,
                            white[(i + 1) % 3].second);
        }
        break;
      }
      case 2: {
        for (int i = 0; i < 2; ++i) {
          ans_.emplace_back(
              black[i].first,
              black[i].second,
              white[0].first,
              white[0].second,
              white[1].first,
              white[1].second);
        }
        break;
      }
      case 3: {
        ans_.emplace_back(
            black[0].first,
            black[0].second,
            black[1].first,
            black[1].second,
            black[2].first,
            black[2].second);
        break;
      }
      case 4: {
        ans_.emplace_back(
            black[0].first,
            black[0].second,
            black[1].first,
            black[1].second,
            black[2].first,
            black[2].second);
        ans_.emplace_back(
            black[0].first,
            black[0].second,
            black[2].first,
            black[2].second,
            black[3].first,
            black[3].second);
        ans_.emplace_back(
            black[0].first,
            black[0].second,
            black[1].first,
            black[1].second,
            black[3].first,
            black[3].second);
        ans_.emplace_back(
            black[1].first,
            black[1].second,
            black[2].first,
            black[2].second,
            black[3].first,
            black[3].second);
        break;
      }
    }
  }

  int n_, m_;
  std::vector<std::string> grid_;
  std::vector<std::tuple<int, int, int, int, int, int>> ans_;
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solver solver;
    solver.Solve();
  }
}