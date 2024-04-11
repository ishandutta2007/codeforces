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
    for (int j = 0; j < n; j++){
      int b;
      cin >> b;
      string s;
      cin >> s;
      for (int k = 0; k < b; k++){
        if (s[k]== 'U'){
          a[j]--;
          if (a[j] == -1){
            a[j] = 9;
          }
        } else {
          a[j]++;
          if (a[j] == 10){
            a[j] = 0;
          }
        }
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