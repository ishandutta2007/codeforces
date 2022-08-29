#include <bits/stdc++.h>
using namespace std;
const int B = 300;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> pp(n);
  for (int i = 0; i < n; i++){
    pp[i] = i;
    for (int j = 0; j < B; j++){
      pp[i] = p[pp[i]];
    }
  }
  vector<int> inv(n);
  for (int i = 0; i < n; i++){
    inv[p[i]] = i;
  }
  vector<bool> ok(n, true);
  for (int j = 0; j < q; j++){
    int t;
    cin >> t;
    if (t == 1){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      vector<int> A;
      int x2 = x;
      for (int k = 0; k <= B; k++){
        A.push_back(x2);
        x2 = inv[x2];
        if (x2 == x){
          break;
        }
      }
      int y2 = y;
      for (int k = 0; k <= B; k++){
        A.push_back(y2);
        y2 = inv[y2];
        if (y2 == y){
          break;
        }
      }
      swap(p[x], p[y]);
      swap(inv[p[x]], inv[p[y]]);
      for (int a : A){
        ok[a] = false;
      }
      for (int a : A){
        if (!ok[a]){
          if (ok[p[a]]){
            pp[a] = inv[pp[p[a]]];
          } else {
            pp[a] = a;
            for (int k = 0; k < B; k++){
              pp[a] = p[pp[a]];
            }
          }
          ok[a] = true;
        }
      }
    }
    if (t == 2){
      int i, k;
      cin >> i >> k;
      i--;
      while (k >= B){
        i = pp[i];
        k -= B;
      }
      while (k > 0){
        i = p[i];
        k--;
      }
      cout << i + 1 << "\n";
    }
  }
}