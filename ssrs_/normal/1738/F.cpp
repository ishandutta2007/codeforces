#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N){
    p = vector<int>(N, -1);
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -p[root(x)];
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      if (p[x] < p[y]){
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> d(n);
    for (int j = 0; j < n; j++){
      cin >> d[j];
    }
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(d[j], j);
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    vector<bool> used(n, false);
    unionfind UF(n);
    for (int j = 0; j < n; j++){
      int v = P[j].second;
      if (!used[v]){
        used[v] = true;
        for (int k = 0; k < d[v]; k++){
          cout << "? " << v + 1 << endl;
          int x;
          cin >> x;
          x--;
          UF.unite(v, x);
          if (used[x]){
            break;
          }
          used[x] = true;
        }
      }
    }
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      c[j] = UF.root(j);
    }
    cout << "!";
    for (int j = 0; j < n; j++){
      cout << " " << c[j] + 1;
    }
    cout << endl;
  }
}