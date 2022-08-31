#include <bits/stdc++.h>
using namespace std;
pair<int, int> L = make_pair(-1, -1);
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> P(n, vector<pair<int, int>>(n));
  set<pair<int, int>> S;
  set<pair<int, int>> S2;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> P[i][j].first >> P[i][j].second;
      if (P[i][j] != L){
        P[i][j].first--;
        P[i][j].second--;
        S.insert(P[i][j]);
      } else {
        S2.insert(make_pair(i, j));
      }
    }
  }
  vector<vector<char>> B(n, vector<char>(n, '?'));
  bool valid = true;
  for (auto p : S2){
    int i = p.first;
    int j = p.second;
    if (P[i][j] != L){
      continue;
    }
    bool flg = false;
    //U
    if (i != 0){
      if (P[i - 1][j] == L){
        flg = true;
        B[i][j] = 'U';
      }
    }
    //D
    if (i != n - 1){
      if (P[i + 1][j] == L){
         flg = true;
        B[i][j] = 'D';
      }
    }
    //L
    if (j != 0){
      if (P[i][j - 1] == L){
        flg = true;
        B[i][j] = 'L';
      }
    }
    //R
    if (j != n - 1){
      if (P[i][j + 1] == L){
        flg = true;
        B[i][j] = 'R';
      }
    }
    if (!flg){
      valid = false;
    }
  }
  if (!valid){
    cout << "INVALID";
  } else {
    for (auto p : S){
      int y = p.first;
      int x = p.second;
      if (B[y][x] != '?'){
        valid = false;
      } else if (P[y][x] != p){
        valid = false;
      } else {
        B[y][x] = 'X';
        stack<pair<int, int>> s;
        s.push(p);
        while (!s.empty()){
          pair<int, int> p2 = s.top();
          s.pop();
          int y2 = p2.first;
          int x2 = p2.second;
          //U
          if (y2 != 0){
            if (P[y2 - 1][x2] == p && B[y2 - 1][x2] == '?'){
              B[y2 - 1][x2] = 'D';
              s.push(make_pair(y2 - 1, x2));
            }
          }
          //D
          if (y2 != n - 1){
            if (P[y2 + 1][x2] == p && B[y2 + 1][x2] == '?'){
              B[y2 + 1][x2] = 'U';
              s.push(make_pair(y2 + 1, x2));
            }
          }
          //L
          if (x2 != 0){
            if (P[y2][x2 - 1] == p && B[y2][x2 - 1] == '?'){
              B[y2][x2 - 1] = 'R';
              s.push(make_pair(y2, x2 - 1));
            }
          }
          //R
          if (x2 != n - 1){
            if (P[y2][x2 + 1] == p && B[y2][x2 + 1] == '?'){
              B[y2][x2 + 1] = 'L';
              s.push(make_pair(y2, x2 + 1));
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (B[i][j] == '?'){
          valid = false;
        }
      }
    }
    if (!valid){
      cout << "INVALID" << endl;
    } else {
      cout << "VALID" << endl;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          cout << B[i][j];
        }
        cout << endl;
      }
    }
  }
}