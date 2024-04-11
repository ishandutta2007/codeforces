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
      a[j]--;
    }
    vector<int> d(n);
    for (int j = n - 1; j >= 0; j--){
      int p;
      for (int k = 0; k <= j; k++){
        if (a[k] == j){
          p = k;
        }
      }
      if (p == j){
        d[j] = 0;
      } else {
        d[j] = p + 1;
      }
      rotate(a.begin(), a.begin() + p + 1, a.begin() + j + 1);
    }
    for (int j = 0; j < n; j++){
      cout << d[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}