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
    int odd = 0, even = 0;
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 1){
        odd++;
      } else {
        even++;
      }
    }
    if (odd == 0){
      cout << "No" << endl;
    } else if (even == 0){
      if (x % 2 == 0){
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    } else if (odd % 2 == 0 && x == n){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}