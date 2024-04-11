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
    int k = 1;
    for (int j = 0; j < n; j++){
      if (a[j] == 0){
        if (j > 0){
          if (a[j - 1] == 0){
            k = -1;
            break;
          }
        }
      }
      if (a[j] == 1){
        if (j == 0){
          k++;
        } else if (a[j - 1] == 0){
          k++;
        } else {
          k += 5;
        }
      }
    }
    cout << k << endl;
  }
}