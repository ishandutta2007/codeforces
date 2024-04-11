#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<vector<int>> R(n);
  for (int i = 0; i < k; i++){
    R[x[i]].push_back(y[i]);
  }
  for (int i = 0; i < n; i++){
    R[i].push_back(-1);
    R[i].push_back(m);
    sort(R[i].begin(), R[i].end());
  }
  vector<vector<int>> C(m);
  for (int i = 0; i < k; i++){
    C[y[i]].push_back(x[i]);
  }
  for (int i = 0; i < m; i++){
    C[i].push_back(-1);
    C[i].push_back(n);
    sort(C[i].begin(), C[i].end());
  }
  int X = 0, Y = 0;
  int d = 0;
  int left = -1, right = m;
  int up = -1, down = n;
  long long num = 1;
  while (1){
    if (d == 0){
      int next = min(right, *lower_bound(R[X].begin(), R[X].end(), Y)) - 1;
      if (next == Y){
        if (num > 1){
          break;
        }
      }
      num += next - Y;
      up = X;
      Y = next;
    }
    if (d == 1){
      int next = min(down, *lower_bound(C[Y].begin(), C[Y].end(), X)) - 1;
      if (next == X){
        break;
      }
      num += next - X;
      right = Y;
      X = next;
    }
    if (d == 2){
      int next = max(left, *(lower_bound(R[X].begin(), R[X].end(), Y) - 1)) + 1;
      if (next == Y){
        break;
      }
      num += Y - next;
      down = X;
      Y = next;
    }
    if (d == 3){
      int next = max(up, *(lower_bound(C[Y].begin(), C[Y].end(), X) - 1)) + 1;
      if (next == X){
        break;
      }
      num += X - next;
      left = Y;
      X = next;
    }
    d = (d + 1) % 4;
  }
  if (num + k == (long long) n * m){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}