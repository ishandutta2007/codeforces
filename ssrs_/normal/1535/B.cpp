#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b;
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 0){
        b.push_back(a[j]);
      }
    }
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 1){
        b.push_back(a[j]);
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (gcd(b[j], b[k] * 2) > 1){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}