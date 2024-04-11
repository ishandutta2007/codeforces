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
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (a[j] != x){
        cnt++;
      }
    }
    if (cnt == 0){
      cout << 0 << endl;
    } else if (cnt < n - 1){
      cout << 1 << endl;
    } else if (cnt == n - 1){
      int sum = 0;
      for (int j = 0; j < n; j++){
        sum += a[j];
      }
      bool one = false;
      for (int j = 0; j < n; j++){
        if ((sum - j * x) % (n - j) == 0){
          one = true;
        }
      }
      if (one){
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else {
      int sum = 0;
      for (int j = 0; j < n; j++){
        sum += a[j];
      }
      if (sum == x * n){
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}