#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int IN = 1;
constexpr int OUT = 2;
constexpr int LEFT = 4;
constexpr int RAIT = 8;
constexpr int dr[4] = {-1, 1, 0, 0};
constexpr int da[4] = {0, 0, -1, 1};

void solve() {
  vector<vector<int>> moves(22, vector<int>(360, 15));

  int n;
  cin >> n;
  while (n--) {
    char ch;
    cin >> ch;
    if (ch == 'C') {
      int r, a1, a2;
      cin >> r >> a1 >> a2;
      for (int i = a1; i != a2; i = (i + 1) % 360) {
        moves[r - 1][i] &= (~OUT);
        moves[r][i] &= (~IN);
      }
    } else {
      int r1, r2, a;
      cin >> r1 >> r2 >> a;
      int a2 = (a + 359) % 360;
      for (int i = r1; i < r2; i++) {
        moves[i][a] &= (~LEFT);
        moves[i][a2] &= (~RAIT);
      }
    }
  }

  for (int a = 0; a < 360; a++) {
    moves[0][a] &= (~IN);
  }

  vector<vector<int>> dist(22, vector<int>(360, -1));
  dist[0][0] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));

  while (!q.empty()) {
    auto &[r, a] = q.front();
    q.pop();
    if (r > 20) {
      cout << "YES\n";
      return;
    }
    for (int dir = 0; dir < 4; dir++) {
      int rr = r + dr[dir];
      int aa = (a + 360 + da[dir]) % 360;
      if (rr >= 0 && (moves[r][a] & (1 << dir)) && dist[rr][aa] == -1) {
        dist[rr][aa] = dist[r][a] + 1;
        q.push(make_pair(rr, aa));
      }
    }
  }

  cout << "NO\n";
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 4;
  }
  cin >> t;
  while (t--) {
    solve();
  }
}