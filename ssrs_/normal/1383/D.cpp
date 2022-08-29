#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> A[i][j];
    }
  }
  vector<int> R(n, 0), C(m, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      R[i] = max(R[i], A[i][j]);
      C[j] = max(C[j], A[i][j]);
    }
  }
  sort(R.rbegin(), R.rend());
  sort(C.rbegin(), C.rend());
  R.push_back(0);
  C.push_back(0);
  vector<vector<int>> B(n, vector<int>(m, 0));
  int a = 0;
  int b = 0;
  while (a < n || b < m){
    if (R[a] == C[b]){
      B[a][b] = R[a];
      a++;
      b++;
    } else if (R[a] < C[b]){
      B[a - 1][b] = C[b];
      b++;
    } else {
      B[a][b - 1] = R[a];
      a++;
    }
  }
  for (int i = 0; i < n; i++){
    int tmp = -1;
    for (int j = 0; j < m; j++){
      if (B[i][j] == 0){
        B[i][j] = tmp;
      } else {
        tmp = -2;
      }
    }
  }
  set<int> st;
  for (int i = 1; i <= n * m; i++){
    st.insert(i);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (B[i][j] > 0){
        st.erase(B[i][j]);
      }
    }
  }
  priority_queue<pair<int, pair<int, int>>> Q;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (B[i][j] == -1){
        if (B[i - 1][j] > 0 && B[i][j + 1] > 0){
          Q.push(make_pair(min(B[i - 1][j], B[i][j + 1]), make_pair(i, j)));
        }
      }
      if (B[i][j] == -2){
        if (B[i][j - 1] > 0 && B[i + 1][j] > 0){
          Q.push(make_pair(min(B[i][j - 1], B[i + 1][j]), make_pair(i, j)));
        }
      }
    }
  }
  bool ok = true;
  while (!Q.empty()){
    int d = Q.top().first;
    int y = Q.top().second.first;
    int x = Q.top().second.second;
    Q.pop();
    int type = B[y][x];
    B[y][x] = *st.rbegin();
    if (B[y][x] > d){
      ok = false;
      break;
    }
    st.erase(prev(st.end()));
    if (type == -2){
      if (y > 0 && x > 0){
        if (B[y - 1][x - 1] > 0){
          Q.push(make_pair(min(B[y][x], B[y - 1][x - 1]), make_pair(y - 1, x)));
        }
      }
      if (y < n - 1 && x < m - 1){
        if (B[y + 1][x + 1] > 0){
          Q.push(make_pair(min(B[y][x], B[y + 1][x + 1]), make_pair(y, x + 1)));
        }
      }
    } else {
      if (y > 0 && x > 0){
        if (B[y - 1][x - 1] > 0){
          Q.push(make_pair(min(B[y][x], B[y - 1][x - 1]), make_pair(y, x - 1)));
        }
      }
      if (y < n - 1 && x < m - 1){
        if (B[y + 1][x + 1] > 0){
          Q.push(make_pair(min(B[y][x], B[y + 1][x + 1]), make_pair(y + 1, x)));
        }
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cout << B[i][j];
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}