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
    int x = 0;
    for (int j = 0; j < n; j++){
      x ^= a[j];
    }
    if (x == 0){
      cout << "YES" << endl;
    } else {
      int cnt = 0;
      int x2 = 0;
      for (int j = 0; j < n; j++){
        x2 ^= a[j];
        if (x2 == x){
          x2 = 0;
          cnt++;
        }
      }
      if (cnt >= 3){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}