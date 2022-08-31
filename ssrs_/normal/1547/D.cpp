#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<int> y(n);
    y[0] = 0;
    int p = x[0];
    for (int j = 1; j < n; j++){
      int p2 = p | x[j];
      y[j] = x[j] ^ p2;
      p = p2;
    }
    for (int j = 0; j < n; j++){
      cout << y[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}