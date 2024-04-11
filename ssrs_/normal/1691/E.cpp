#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<int>> &E, int L, int R, int x, int f, int i, int l, int r){
  if (r <= L || R <= l){
    return;
  } else if (L <= l && r <= R){
    E[x].push_back(f + i);
  } else {
    int m = (l + r) / 2;
    dfs1(E, L, R, x, f, i * 2 + 1, l, m);
    dfs1(E, L, R, x, f, i * 2 + 2, m, r);
  }
}
void dfs2(vector<vector<int>> &E, int L, int R, int x, int f, int i, int l, int r){
  if (r <= L || R <= l){
    return;
  } else if (L <= l && r <= R){
    E[f + i].push_back(x);
  } else {
    int m = (l + r) / 2;
    dfs2(E, L, R, x, f, i * 2 + 1, l, m);
    dfs2(E, L, R, x, f, i * 2 + 2, m, r);
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> c(n), l(n), r(n);
    for (int j = 0; j < n; j++){
      cin >> c[j] >> l[j] >> r[j];
      r[j]++;
    }
    vector<int> X;
    for (int j = 0; j < n; j++){
      X.push_back(l[j]);
      X.push_back(r[j]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    int cnt = X.size();
    for (int j = 0; j < n; j++){
      l[j] = lower_bound(X.begin(), X.end(), l[j]) - X.begin();
      r[j] = lower_bound(X.begin(), X.end(), r[j]) - X.begin();
    }
    int cnt2 = 1;
    while (cnt2 < cnt){
      cnt2 *= 2;
    }
    int T = cnt2 * 2 - 1;
    vector<vector<int>> E(T * 4 + n);
    for (int j = 0; j < 4; j++){
      for (int k = 0; k < cnt2 - 1; k++){
        if (j % 2 == 0){
          E[T * j + k].push_back(T * j + k * 2 + 1);
          E[T * j + k].push_back(T * j + k * 2 + 2);
        } else {
          E[T * j + k * 2 + 1].push_back(T * j + k);
          E[T * j + k * 2 + 2].push_back(T * j + k);
        }
      }
    }
    for (int j = 0; j < 4; j += 2){
      for (int k = cnt2 - 1; k < T; k++){
        E[T * j + k].push_back(T * (j + 1) + k);
      }
    }
    for (int j = 0; j < n; j++){
      if (c[j] == 0){
        dfs1(E, l[j], r[j], T * 4 + j, 0, 0, 0, cnt2);
        dfs2(E, l[j], r[j], T * 4 + j, T * 3, 0, 0, cnt2);
      }
      if (c[j] == 1){
        dfs1(E, l[j], r[j], T * 4 + j, T * 2, 0, 0, cnt2);
        dfs2(E, l[j], r[j], T * 4 + j, T, 0, 0, cnt2);
      }
    }
    vector<bool> used(T * 4 + n, false);
    int k = 0;
    for (int j = T * 4; j < T * 4 + n; j++){
      if (!used[j]){
        used[j] = true;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        k++;
      }
    }
    cout << k << "\n";
  }
}