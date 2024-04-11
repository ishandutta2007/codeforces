#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(k, 1);
    n -= k - 3;
    if (n % 2 == 1){
      a[0] = 1;
      a[1] = (n - 1) / 2;
      a[2] = (n - 1) / 2;
    }
    if (n % 4 == 0){
      a[0] = n / 4;
      a[1] = n / 4;
      a[2] = n / 2;
    }
    if (n % 4 == 2){
      a[0] = 2;
      a[1] = (n - 2) / 2;
      a[2] = (n - 2) / 2;
    }
    for (int j = 0; j < k; j++){
      cout << a[j];
      if (j < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}