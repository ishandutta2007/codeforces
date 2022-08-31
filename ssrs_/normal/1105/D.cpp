#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> s(p);
  for (int i = 0; i < p; i++){
    cin >> s[i];
  }
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<vector<int>> id(n, vector<int>(m, -1));
  vector<queue<tuple<int, int, int>>> Q(p);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (isdigit(S[i][j])){
        int P = S[i][j] - '1';
        id[i][j] = P;
        for (int k = 0; k < 4; k++){
          int x = i + dx[k];
          int y = j + dy[k];
          if (0 <= x && x < n && 0 <= y && y < m){
            if (S[x][y] == '.'){
              Q[P].push(make_tuple(x, y, 1));
            }
          }
        }
      }
    }
  }
  int t = 0;
  while (true){
    t++;
    bool update = false;
    for (int i = 0; i < p; i++){
      while (!Q[i].empty()){
        int x = get<0>(Q[i].front());
        int y = get<1>(Q[i].front());
        int ct = get<2>(Q[i].front());
        if (ct > t * s[i]){
          break;
        }
        Q[i].pop();
        if (id[x][y] == -1){
          update = true;
          id[x][y] = i;
          for (int j = 0; j < 4; j++){
            int x2 = x + dx[j];
            int y2 = y + dy[j];
            if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m){
              if (S[x2][y2] == '.'){
                if (id[x2][y2] == -1){
                  Q[i].push(make_tuple(x2, y2, ct + 1));
                }
              }
            }
          }
        }
      }
    }
    if (!update){
      break;
    }
  }
  vector<int> ans(p, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (id[i][j] != -1){
        ans[id[i][j]]++;
      }
    }
  }
  for (int i = 0; i < p; i++){
    cout << ans[i];
    if (i < p - 1){
      cout << ' ';
    }
  }
  cout << endl;
}