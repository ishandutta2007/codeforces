#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x, y;
    int m = 0;
    if (n > 32){
      for (int j = 32; j <= n - 2; j++){
        x.push_back(j);
        y.push_back(n - 1);
        m++;
      }
      int L = n;
      while (L > 1){
        x.push_back(n - 1);
        y.push_back(31);
        m++;
        L = (L + 31) / 32;
      }
      n = 32;
    }
    for (int j = 2; j <= n - 2; j++){
      x.push_back(j);
      y.push_back(n - 1);
      m++;
    }
    for (int j = 0; j < 5; j++){
      x.push_back(n - 1);
      y.push_back(1);
      m++;
    }
    cout << m << endl;
    for (int j = 0; j < m; j++){
      cout << x[j] + 1 << ' ' << y[j] + 1 << endl;
    }
  }
}