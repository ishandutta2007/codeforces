#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> c(n);
    vector<vector<int>> g(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
      for (int k = 0; k < c[j]; k++){
        int x;
        cin >> x;
        g[j].push_back(x - 1);
      }
    }
    vector<int> r1(n, -1);
    vector<int> r2(n, -1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < c[j]; k++){
        if (r2[g[j][k]] == -1){
          r1[j] = g[j][k];
          r2[g[j][k]] = j;
          break;
        }
      }
    }
    bool flg = false;
    for (int j = 0; j < n; j++){
      if (r1[j] == -1){
        flg = true;
      }
    }
    if (!flg){
      cout << "OPTIMAL" << endl;
    } else {
      cout << "IMPROVE" << endl;
      int a, b;
      for (int j = 0; j < n; j++){
        if (r1[j] == -1){
          a = j;
        }
        if (r2[j] == -1){
          b = j;
        }
      }
      cout << a + 1 << ' ' << b + 1 << endl;
    }
    /*
    for (int j = 0; j < n; j++) cout << r1[j] << ' ';
    cout << endl;
    for (int j = 0; j < n; j++) cout << r2[j] << ' ';
    cout << endl;
    */
  }
}