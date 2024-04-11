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
    int L = 0;
    for (int j = 0; j < n; j++){
      if (a[j] < j){
        break;
      }
      L++;
    }
    int R = 0;
    for (int j = n - 1; j >= 0; j--){
      if (a[j] < n - 1 - j){
        break;
      }
      R++;
    }
    if (L + R > n){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}