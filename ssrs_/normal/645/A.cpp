#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  vector<string> S(2);
  cin >> S[0];
  cin >> S[1];
  vector<string> T(2);
  cin >> T[0];
  cin >> T[1];
  set<vector<string>> used;
  used.insert(S);
  queue<vector<string>> Q;
  Q.push(S);
  while (!Q.empty()){
    vector<string> A = Q.front();
    Q.pop();
    int x, y;
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 2; j++){
        if (A[i][j] == 'X'){
          x = i;
          y = j;
        }
      }
    }
    for (int i = 0; i < 4; i++){
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (0 <= x2 && x2 < 2 && 0 <= y2 && y2 < 2){
        vector<string> B = A;
        swap(B[x][y], B[x2][y2]);
        if (used.count(B) == 0){
          used.insert(B);
          Q.push(B);
        }
      }
    }
  }
  if (used.count(T) == 1){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}