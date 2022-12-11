#include <bits/stdc++.h>
using namespace std;

struct ANS {
  char ch;
  int y, x;
  ANS(char ch, int y, int x): ch(ch), y(y), x(x) {}  
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isOk(int y, int x, vector<vector<bool>> &u) { 
  int n = u.size();
  int m = u[0].size();  
  return 0 <= y && y < n && 0 <= x && x < m && !u[y][x]; 
}

void go(vector<ANS> &ans, vector<vector<bool>> &u, int y, int x) {

  ans.push_back(ANS('B', y, x));  
  for (int dir = 0; dir < 4; dir++) {
    int yy = y + dy[dir];
    int xx = x + dx[dir];
    if (isOk(yy, xx, u)) {
      u[yy][xx] = true;
      go(ans, u, yy, xx);
    }
  }
  ans.push_back(ANS('D', y, x)); 
  ans.push_back(ANS('R', y, x));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  vector<vector<bool>> u(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '#') u[i][j] = true;
    }
  }

  vector<ANS> ans;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!u[i][j]) {
        u[i][j] = true;
        go(ans, u, i, j);
        ans.pop_back();
        ans.pop_back();
      }
    }
  }

  cout << ans.size() << "\n";
  for (const auto &x : ans) {
    cout << x.ch << " " << x.y + 1 << " " << x.x + 1 << "\n";
  }
}