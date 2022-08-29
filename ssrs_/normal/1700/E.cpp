#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0, 0};
vector<int> dy = {0, 1, 0, -1, 0};
bool check(vector<vector<int>> &a, int x, int y){
  int n = a.size();
  int m = a[0].size();
  if (a[x][y] == 0){
    return true;
  }
  for (int i = 0; i < 4; i++){
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m){
      if (a[x2][y2] < a[x][y]){
        return true;
      }
    }
  }
  return false;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<int> x(n * m), y(n * m);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      x[a[i][j]] = i;
      y[a[i][j]] = j;
    }
  }
  vector<int> ng;
  for (int i = 0; i < n * m; i++){
    if (!check(a, x[i], y[i])){
      ng.push_back(i);
    }
  }
  if (ng.empty()){
    cout << 0 << endl;
  } else if (ng.size() >= 6){
    cout << 2 << endl;
  } else {
    int cnt = ng.size();
    set<pair<int, int>> st;
    for (int i = 0; i < 5; i++){
      int x1 = x[ng[0]] + dx[i];
      int y1 = y[ng[0]] + dy[i];
      if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m){
        for (int x2 = 0; x2 < n; x2++){
          for (int y2 = 0; y2 < m; y2++){
            swap(a[x1][y1], a[x2][y2]);
            bool ok = true;
            for (int j = 0; j < cnt; j++){
              if (!check(a, x[ng[j]], y[ng[j]])){
                ok = false;
              }
            }
            for (int j = 0; j < 5; j++){
              int cx = x1 + dx[j];
              int cy = y1 + dy[j];
              if (0 <= cx && cx < n && 0 <= cy && cy < m){
                if (!check(a, cx, cy)){
                  ok = false;
                }
              }
            }
            for (int j = 0; j < 5; j++){
              int cx = x2 + dx[j];
              int cy = y2 + dy[j];
              if (0 <= cx && cx < n && 0 <= cy && cy < m){
                if (!check(a, cx, cy)){
                  ok = false;
                }
              }
            }
            if (ok){
              int mn = min(a[x1][y1], a[x2][y2]);
              int mx = max(a[x1][y1], a[x2][y2]);
              st.insert(make_pair(mn, mx));
            }
            swap(a[x1][y1], a[x2][y2]);
          }
        }
      }
    }
    if (st.empty()){
      cout << 2 << endl;
    } else {
      cout << 1 << ' ' << st.size() << endl;
    }
  }
}