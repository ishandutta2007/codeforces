#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      if (j % 2 == 0){
        a[j] = b[j / 2];
      } else {
        a[j] = b[n - 1 - j / 2];
      }
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}