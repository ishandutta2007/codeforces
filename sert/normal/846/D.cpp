#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 34;

struct BRAKE {
  int x, y, t;
  friend istream& operator >> (istream &fi, BRAKE &b) {
    fi >> b.y >> b.x >> b.t;
    b.y--;
    b.x--;
    return fi;
  }
};

const int N = 502;
int a[N][N];

void solve() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<BRAKE> b(q);
  for (auto &x : b) cin >> x;

  int L = -1;
  int R = INF;

  while (R - L > 1) {
    int M = (L + R) / 2;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        a[i][j] = 0;

    bool ok = false;
    for (const auto &x : b)
      if (x.t <= M) {
        a[x.y][x.x] = 1;
      }
    
    for (int i = 0; i < n; i++) {      
      int num = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1 && i > 0)
          a[i][j] += a[i - 1][j];
        if (a[i][j] >= k) {
          num++;
          if (num >= k) ok = true;          
        } else num = 0;
      }
    }
      
    if (ok) R = M;
    else L = M;
  }

  if (R == INF) cout << "-1\n";
  else cout << R << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}