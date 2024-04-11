#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

using Table = vector<string>;
void print(const Table &t) {
  for (auto row : t)
    cout << row << "\n";
  cout << "\n";
}

void print(const vector<pair<int, int>> &t) {
  for (auto x : t)
    cout << "[" << x.first << "," << x.second << "] ";
  cout << "\n";
}

pair<Table, Table> turn(const Table &t) {
  int n = t.size();
  int m = t[0].size();
  int nn = (n + m) / 2;
  int mm = (n + m) / 2;
  Table r1(nn, string(mm, '0'));
  Table r2(nn, string(mm, '0'));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      Table &r = ((i + j) % 2 ? r1 : r2);
      r[(i + j) / 2][(i - j + m - 1) / 2] = t[i][j];
    }  
  return {r1, r2};
}

vector<pair<int, int>> gen1(pair<int, int> a, int side) {
  int y = a.first, x = a.second;
  vector<pair<int, int>> ans;
  ans.reserve(side * 4);
  for (int i = 0; i <= side; i++) ans.emplace_back(y, x + i);
  for (int i = 1; i < side; i++) {
    ans.emplace_back(y + i, x);
    ans.emplace_back(y + i, x + side);
  }
  for (int i = 0; i <= side; i++) ans.emplace_back(y + side, x + i);

  return ans;
}

vector<pair<int, int>> gen2(pair<int, int> a, int side) {
  int y = a.first, x = a.second;
  vector<pair<int, int>> ans;
  ans.reserve(side * 4);
  
  ans.emplace_back(y, x);
  for (int i = 1; i <= side * 2 - 1; i++) {
    int d = min(i, side * 2 - i);
    ans.emplace_back(y + i, x - d);
    ans.emplace_back(y + i, x + d);
  }
  ans.emplace_back(y + side * 2, x);

  return ans;
}


int solve(const Table &t) {
  //print(t);
  int n = t.size();
  int m = t[0].size();
  vector<vector<bool>> u(n, vector<bool>(m, false));

  auto is1 = [&](int y, int x) { return 0 <= y && y < n && 0 <= x && x < m && t[y][x] == '1'; };
  
  int ans = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] == '0' || u[i][j])
        continue;
      q.emplace(i, j);
      vector<pair<int, int>> v = {{i, j}};
      u[i][j] = true;
      while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx != 0 || dy != 0) {
          int yy = y + dy;
          int xx = x + dx;
          if (is1(yy, xx) && !u[yy][xx]) {
            q.emplace(yy, xx);
            v.emplace_back(yy, xx);
            u[yy][xx] = true;
          }
        }
      }
      // cout << v.size() << "\n";
      if (v.size() % 4) continue;
      int side = v.size() / 4;

      sort(v.begin(), v.end());

      // print(v);
      // print(gen1(v[0], side));
      // print(gen2(v[0], side));
      // cout << "\n";

      if (v == gen1(v[0], side))
        ans++;
      else if (v == gen2(v[0], side))
        ans++;
    }
  }

  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  Table t(n);
  for (auto &row : t)
    cin >> row;
  cout << solve(t) << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}