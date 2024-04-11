#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<int> dx2 = {1, 1, -1, -1};
vector<int> dy2 = {1, -1, 1, -1};
const int INF = 100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<vector<bool>> ok(n, vector<bool>(m, true));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (s[j][k] == '#'){
          ok[j][k] = false;
          for (int l = 0; l < 4; l++){
            int x = j + dx[l];
            int y = k + dy[l];
            if (0 <= x && x < n && 0 <= y && y < m){
              ok[x][y] = false;
            }
          }
        }
      }
    }
    vector<vector<int>> d(n, vector<int>(m, INF));
    vector<vector<pair<int, int>>> pr(n, vector<pair<int, int>>(m));
    deque<tuple<int, int, int>> dq;
    for (int j = 0; j < n; j++){
      if (s[j][0] == '#'){
        d[j][0] = 0;
        dq.push_front(make_tuple(0, j, 0));
      } else if (ok[j][0]){
        d[j][0] = 1;
        dq.push_back(make_tuple(1, j, 0));
      }
    }
    while (!dq.empty()){
      int c = get<0>(dq.front());
      int x = get<1>(dq.front());
      int y = get<2>(dq.front());
      dq.pop_front();
      if (d[x][y] == c){
        for (int j = 0; j < 4; j++){
          int x2 = x + dx2[j];
          int y2 = y + dy2[j];
          if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m){
            if (s[x2][y2]  == '#'){
              if (d[x2][y2] > d[x][y]){
                d[x2][y2] = d[x][y];
                pr[x2][y2] = make_pair(x, y);
                dq.push_front(make_tuple(c, x2, y2));
              }
            }
            if (ok[x2][y2]){
              if (d[x2][y2] > d[x][y] + 1){
                d[x2][y2] = d[x][y] + 1;
                pr[x2][y2] = make_pair(x, y);
                dq.push_back(make_tuple(c + 1, x2, y2));
              }
            }
          }
        }
      }
    }
    int mn = INF, p = -1;
    for (int j = 0; j < n; j++){
      if (d[j][m - 1] < mn){
        mn = d[j][m - 1];
        p = j;
      }
    }
    if (p == -1){
      cout << "NO" << "\n";
    } else {
      vector<string> ans = s;
      int x = p, y = m - 1;
      int CNT = 0;
      while (true){
        ans[x][y] = '#';
        if (y == 0){
          break;
        }
        int x2 = pr[x][y].first;
        int y2 = pr[x][y].second;
        x = x2;
        y = y2;
      }
      cout << "YES" << "\n";
      for (int j = 0; j < n; j++){
        cout << ans[j] << "\n";
      }
    }

  }
}