#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int main() {
#ifndef LOCAL
  cout << "? " << N * N << "\n";
  for (int x = 1; x <= N; ++x) {
    for (int y = 1; y <= N; ++y) {
      if (x > 1 || y > 1) {
        cout << " ";
      }
      cout << x << " " << y;
    }
  }
  cout << endl;
#endif
  int area;
  cin >> area;
  vector<pair<int, int>> possible;
  for (int row = 2; row <= N; ++row) {
    if (area % row == 0) {
      int column = area / row;
      if (column >= 2 && column <= N) {
        possible.emplace_back(row, column);
      }
    }
  }
  int m = possible.size();
  map<pair<int, int>, int> go;
  function<bool(int, int)> dfs = [&](int s, int d) {
    if (go.count(make_pair(s, d))) {
      return go[make_pair(s, d)] != -1;
    }
    bool done = true;
    int outcome = -1;
    for (int i = 0; i < m; ++i) {
      if (s >> i & 1) {
        int perimeter = 2 * (possible[i].first + possible[i].second - 2);
        if (outcome == -1) {
          outcome = perimeter;
        } else if (outcome != perimeter) {
          done = false;
          break;
        }
      }
    }
    if (done) {
      go[make_pair(s, d)] = 0;
      return true;
    }
    if (!d) {
      go[make_pair(s, d)] = -1;
      return false;
    }
    for (int step = 1; step <= N; ++step) {
      map<int, int> outcome;
      for (int i = 0; i < m; ++i) {
        if (s >> i & 1) {
          int row = possible[i].first, column = possible[i].second;
          outcome[row / step * column] |= 1 << i;
          outcome[(row + step - 1) / step * column] |= 1 << i;
        }
      }
      bool bad = false;
      for (auto p : outcome) {
        if (p.second == s || !dfs(p.second, d - 1)) {
          bad = true;
          break;
        }
      }
      if (!bad) {
        go[make_pair(s, d)] = step;
        return true;
      }
    }
    go[make_pair(s, d)] = -1;
    return false;
  };
  assert(dfs((1 << m) - 1, 3));
  function<void(int, int)> run = [&](int s, int d) {
    bool done = true;
    int outcome = -1;
    for (int i = 0; i < m; ++i) {
      if (s >> i & 1) {
        int perimeter = 2 * (possible[i].first + possible[i].second - 2);
        if (outcome == -1) {
          outcome = perimeter;
        } else if (outcome != perimeter) {
          done = false;
          break;
        }
      }
    }
    if (done) {
      cout << "! " << outcome << endl;
      return;
    }
    {
      int step = go[make_pair(s, d)];
#ifdef LOCAL
      cout << step << endl;
#else
      cout << "? " << N / step * N << "\n";
      for (int x = 1; x <= N; ++x) {
        for (int y = step; y <= N; y += step) {
          if (x > 1 || y > step) {
            cout << " ";
          }
          cout << x << " " << y;
        }
      }
      cout << endl;
#endif
      int result;
      cin >> result;
      map<int, int> outcome;
      for (int i = 0; i < m; ++i) {
        if (s >> i & 1) {
          int row = possible[i].first, column = possible[i].second;
          outcome[row / step * column] |= 1 << i;
          outcome[(row + step - 1) / step * column] |= 1 << i;
        }
      }
      run(outcome[result], d - 1);
    }
  };
  run((1 << m) - 1, 3);
  return 0;
}