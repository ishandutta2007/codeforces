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
      b[j]--;
    }
    vector<bool> c(n * 2, false);
    for (int j = 0; j < n; j++){
      c[b[j]] = true;
    }
    int mx = 0;
    int curr = 0;
    for (int j = 0; j < n * 2; j++){
      if (c[j]){
        curr++;
      } else {
        if (curr > 0){
          curr--;
          mx++;
        }
      }
    }
    int mn = n;
    int curr2 = 0;
    for (int j = n * 2 - 1; j >= 0; j--){
      if (c[j]){
        curr2++;
      } else {
        if (curr2 > 0){
          curr2--;
          mn--;
        }
      }
    }
    cout << mx - mn + 1 << endl;
  }
}