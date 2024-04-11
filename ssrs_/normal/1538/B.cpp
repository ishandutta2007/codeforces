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
    int s = 0;
    for (int j = 0; j < n; j++){
      s += a[j];
    }
    if (s % n != 0){
      cout << -1 << endl;
    } else {
      int ans = 0;
      for (int j = 0; j < n; j++){
        if (a[j] > s / n){
          ans++;
        }
      }
      cout << ans << endl;
    }
  }
}