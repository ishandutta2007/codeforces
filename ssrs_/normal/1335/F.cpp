#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n, m;
  cin >> n >> m;
  vector<string> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<vector<pair<int, int>>> R(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
  int C = 0; //cycle count
  vector<int> S; //cycle sizes
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (R[i][j].first != -1){
        continue;
      }
      int y = i;
      int x = j;
      int step = 0;
      while (R[y][x].first == -1){
        R[y][x].first = C;
        if (s[y][x] == 'U'){
          y--;
        } else if (s[y][x] == 'D'){
          y++;
        } else if (s[y][x] == 'L'){
          x--;
        } else if (s[y][x] == 'R'){
          x++;
        }
        step++;
      }
      if (R[y][x].first == C){
        //found loop
        //calculate loop size
        int sz = 0;
        int y2 = y;
        int x2 = x;
        while (1){
          if (s[y2][x2] == 'U'){
            y2--;
          } else if (s[y2][x2] == 'D'){
            y2++;
          } else if (s[y2][x2] == 'L'){
            x2--;
          } else if (s[y2][x2] == 'R'){
            x2++;
          }
          sz++;
          if (y2 == y && x2 == x){
            break;
          }
        }
        S.push_back(sz);
        y2 = i;
        x2 = j;
        int p = 0;
        while (R[y2][x2].second == -1){
          R[y2][x2].second = p;
          if (s[y2][x2] == 'U'){
            y2--;
          } else if (s[y2][x2] == 'D'){
            y2++;
          } else if (s[y2][x2] == 'L'){
            x2--;
          } else if (s[y2][x2] == 'R'){
            x2++;
          }
          p++;
          if (p >= sz){
            p = 0;
          }
        }
        C++;
      } else {
        //reached an existing loop
        int curr = R[y][x].second;
        int id = R[y][x].first;
        int sz = S[id];
        int st = (curr - step) % sz;
        if (st < 0){
          st += sz;
        }
        int y2 = i;
        int x2 = j;
        while (R[y2][x2].second == -1){
          R[y2][x2].first = id;
          R[y2][x2].second = st;
          if (s[y2][x2] == 'U'){
            y2--;
          } else if (s[y2][x2] == 'D'){
            y2++;
          } else if (s[y2][x2] == 'L'){
            x2--;
          } else if (s[y2][x2] == 'R'){
            x2++;
          }
          st++;
          if (st >= sz){
            st = 0;
          }
        }
      }
    }
  }
  /*
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << R[i][j].first;
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << R[i][j].second;
    }
    cout << endl;
  }
  */
  vector<vector<int>> count(S.size());
  for (int i = 0; i < S.size(); i++){
    count[i] = vector<int>(S[i], 0);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i][j] == '0'){
        count[R[i][j].first][R[i][j].second]++;
      }
    }
  }
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < S.size(); i++){
    for (int j = 0; j < S[i]; j++){
      ans1++;
      if (count[i][j] > 0){
        ans2++;
      }
    }
  }
  cout << ans1 << ' ' << ans2 << endl;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    solve();
  }
}