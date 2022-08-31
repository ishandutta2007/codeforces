#include <bits/stdc++.h>
using namespace std;
unsigned long long ap(unsigned long long a, unsigned long long b){
  return (b + a) * (b - a + 1) / 2;
}
int main(){
  int n, m;
  cin >> n >> m;
  unsigned long long A, B, C;
  cin >> A >> B >> C;
  vector<unsigned long long> U(m), V(m);
  for (int i = 0; i < m; i++){
    cin >> U[i] >> V[i];
    if (U[i] > V[i]){
      swap(U[i], V[i]);
    }
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    E[U[i]].push_back(V[i]);
    E[V[i]].push_back(U[i]);
  }
  unsigned long long ans = 0;
  for (int i = 1; i < n - 1; i++){
    unsigned long long a = i, c = n - 1 - i;
    ans += ap(0, i - 1) * c * A;
    ans += i * a * c * B;
    ans += a * ap(i + 1, n - 1) * C;
  }
  for (int i = 0; i < m; i++){
    ans -= ap(0, U[i] - 1) * A;
    ans -= U[i] * U[i] * B;
    ans -= U[i] * V[i] * C;
    ans -= (V[i] - U[i] - 1) * U[i] * A;
    ans -= ap(U[i] + 1, V[i] - 1) * B;
    ans -= (V[i] - U[i] - 1) * V[i] * C;
    ans -= (n - 1 - V[i]) * U[i] * A;
    ans -= (n - 1 - V[i]) * V[i] * B;
    ans -= ap(V[i] + 1, n - 1) * C;
  }
  for (int i = 0; i < n; i++){
    sort(E[i].begin(), E[i].end());
    int d = E[i].size();
    vector<unsigned long long> x, y;
    for (int j = 0; j < d; j++){
      if (E[i][j] < i){
        x.push_back(E[i][j]);
      } else {
        y.push_back(E[i][j]);
      }
    }
    unsigned long long X = x.size(), Y = y.size();
    vector<unsigned long long> sx(X + 1);
    sx[0] = 0;
    for (int j = 0; j < X; j++){
      sx[j + 1] = sx[j] + x[j];
    }
    vector<unsigned long long> sy(Y + 1);
    sy[0] = 0;
    for (int j = 0; j < Y; j++){
      sy[j + 1] = sy[j] + y[j];
    }
    for (int j = 0; j < X; j++){
      ans	+= sx[j] * A;
      ans += j * x[j] * B;
      ans += j * i * C;
    }
    ans += sx[X] * Y * A;
    ans += i * (X * Y) * B;
    ans += sy[Y] * X * C;
    for (int j = 0; j < Y; j++){
      ans += j * i * A;
      ans += sy[j] * B;
      ans += j * y[j] * C;
    }
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    d[i] = E[i].size();
  }
  vector<vector<int>> E2(n);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      if (d[i] < d[j] || d[i] == d[j] && i < j){
        E2[i].push_back(j);
      }
    }
  }
  vector<bool> flg(n, false);
  for (int i = 0; i < n; i++){
    for (int j : E2[i]){
      for (int k : E2[i]){
        flg[k] = true;
      }
      for (int k : E2[j]){
        if (flg[k]){
          int a = i, b = j, c = k;
          if (a > b){
            swap(a, b);
          }
          if (b > c){
            swap(b, c);
          }
          if (a > b){
            swap(a, b);
          }
          ans -= a * A + b * B + c * C;
        }
      }
      for (int k : E2[i]){
        flg[k] = false;
      }
    }
  }
  cout << ans << endl;
}