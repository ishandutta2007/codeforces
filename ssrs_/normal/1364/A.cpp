#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> S(n + 1, 0);
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
      S[j + 1] %= x;
    }
    bool ok = false;
    for (int j = 1; j <= n; j++){
      if (S[j] != 0){
        ok = true;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n; j++){
        if (S[j] != S[n] || S[n - j] != S[0]){
          cout << n - j << endl;
          break;
        }
      }
    }
  }
}