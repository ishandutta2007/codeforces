#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin >> k;
  bool ok = false;
  for (int i = 5; i <= k; i++){
    if (k % i == 0 && k / i >= 5){
      int n = i;
      int m = k / i;
      string S = "aeiou";
      for (int j = 0; j < n; j++){
        for (int l = 0; l < m; l++){
          cout << S[(j + l) % 5];
        }
      }
      cout << endl;
      ok = true;
      break;
    }
  }
  if (!ok){
    cout << -1 << endl;
  }
}