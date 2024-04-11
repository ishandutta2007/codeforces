#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    bool ok = false;
    while (true){
      int R = -1;
      for (int j = 0; j < n - 1; j++){
        if (h[j] < h[j + 1]){
          R = j;
          break;
        }
      }
      if (R == -1){
        break;
      }
      int L = 0;
      for (int j = R - 1; j >= 0; j--){
        if (h[j] != h[R]){
          L = j + 1;
          break;
        }
      }
      int d = h[R + 1] - h[R];
      if (L > 0){
        d = min(d, h[L - 1] - h[L]);
      }
      int c = R - L + 1;
      if (k <= d * c){
        cout << R - (k - 1) % c + 1 << endl;
        ok = true;
        break;
      } else {
        k -= d * c;
        for (int j = L; j <= R; j++){
          h[j] += d;
        }
      }
    }
    if (!ok){
      cout << -1 << endl;
    }
  }
}