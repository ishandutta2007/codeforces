#include <bits/stdc++.h>
using namespace std;
const int M = 100;
struct segment_tree{
  int N;
  vector<array<int, M>> ST;
  segment_tree(int n){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<array<int, M>>(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; i++){
      for (int j = 0; j < M; j++){
        ST[i][j] = j;
      }
    }
  }
  void update(int p, array<int, M> &x){
    p += N - 1;
    ST[p] = x;
    while (p > 0){
      p = (p - 1) / 2;
      for (int i = 0; i < M; i++){
        ST[p][i] = ST[p * 2 + 2][ST[p * 2 + 1][i]];
      }
    }
  }
  int get(int x){
    return ST[0][x];
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  int q;
  cin >> q;
  vector<int> l(q), r(q), x(q), y(q);
  for (int i = 0; i < q; i++){
    cin >> l[i] >> r[i] >> x[i] >> y[i];
    l[i]--;
    x[i]--;
    y[i]--;
  }
  vector<vector<int>> add(n + 1), sub(n + 1);
  for (int i = 0; i < q; i++){
    add[l[i]].push_back(i);
    sub[r[i]].push_back(i);
  }
  array<int, M> E;
  for (int i = 0; i < M; i++){
    E[i] = i;
  }
  segment_tree ST(q);
  for (int i = 0; i < n; i++){
    for (int j : add[i]){
      E[x[j]] = y[j];
      ST.update(j, E);
      E[x[j]] = x[j];
    }
    for (int j : sub[i]){
      ST.update(j, E);
    }
    cout << ST.get(a[i]) + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}