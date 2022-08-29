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
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    long long sum2 = 0;
    for (int j = 0; j < n; j++){
      if (j % 2 == 0){
        sum2 += a[j] - 1;
      }
    }
    vector<int> b = a;
    if (sum2 * 2 <= sum){
      for (int j = 0; j < n; j++){
        if (j % 2 == 0){
          b[j] = 1;
        }
      }
    } else {
      for (int j = 0; j < n; j++){
        if (j % 2 == 1){
          b[j] = 1;
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << b[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}