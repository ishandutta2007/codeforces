#include <bits/stdc++.h>
using namespace std;
vector<int> C = {-1, 0, 0, 1, 0, -1, 1, 1, 0, 1, -1, 1, 1, 0, 1, -1, 0, 0, 1, 0};
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
    int x = -1;
    for (int j = 0; j < n; j++){
      if (a[j] % 5 == 0){
        x = a[j];
      }
    }
    if (x != -1){
      if (x % 10 == 0){
        x -= 5;
      }
      bool ok = true;
      for (int j = 0; j < n; j++){
        if (a[j] != x && a[j] != x + 5){
          ok = false;
        }
      }
      if (ok){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      bool ok = true;
      for (int j = 1; j < n; j++){
        if (C[a[j] % 20] != C[a[0] % 20]){
          ok = false;
        }
      }
      if (ok){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}