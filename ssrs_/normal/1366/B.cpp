#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x, m;
    cin >> n >> x >> m;
    int L = x;
    int R = x + 1;
    for (int j = 0; j < m; j++){
      int l, r;
      cin >> l >> r;
      r++;
      if (r <= L || R <= l){
        continue;
      } else {
        L = min(L, l);
        R = max(R, r);
      }
    }
    cout << R - L << endl;
  }
}