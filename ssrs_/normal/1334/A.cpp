#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++){
      cin >> p[i] >> c[i];
    }
    bool flg = true;
    for (int i = 0; i < n; i++){
      if (p[i] < c[i]){
        flg = false;
      }
    }
    for (int i = 1; i < n; i++){
      if (p[i - 1] > p[i]){
        flg = false;
      }
      if (c[i - 1] > c[i]){
        flg = false;
      }
      if (p[i - 1] - c[i - 1] > p[i] - c[i]){
        flg = false;
      }
    }
    if (flg){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}