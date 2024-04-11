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
    for (int x = 0; x + 1 < n_; ++x) {
      for (int y = 0; y + 1 < m_; ++y) {
        SolveSubGrid(x, y);
      }
    }
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