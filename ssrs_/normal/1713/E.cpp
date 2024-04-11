#include <bits/stdc++.h>
using namespace std;
struct weighted_unionfind{
  vector<int> p;
  vector<int> d;
  weighted_unionfind(int N){
    p = vector<int>(N, -1);
    d = vector<int>(N, 0);
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      int r = root(p[x]);
      d[x] ^= d[p[x]];
      p[x] = r;
      return r;
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y, int w){
    w ^= d[x];
    w ^= d[y];
    x = root(x);
    y = root(y);
    p[y] = x;
    d[y] = w;
  }
  int diff(int x, int y){
    root(x);
    root(y);
    return d[y] ^ d[x];
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cin >> A[j][k];
      }
    }
    weighted_unionfind UF(n);
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (!UF.same(j, k)){
          if (A[k][j] < A[j][k]){
            UF.unite(j, k, 1);
          }
          if (A[k][j] > A[j][k]){
            UF.unite(j, k, 0);
          }
        }
      }
    }
    for (int j = 1; j < n; j++){
      if (!UF.same(j, 0)){
        UF.unite(j, 0, 0);
      }
    }
    vector<bool> f(n, false);
    for (int j = 0; j < n; j++){
      if (UF.diff(0, j) == 1){
        f[j] = true;
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (f[j] ^ f[k]){
          swap(A[j][k], A[k][j]);
        }
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cout << A[j][k];
        if (k < n - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }
  }
}