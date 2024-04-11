#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (c[j] == 1){
        cnt++;
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (c[(j + 1) % n] - c[j] >= 2){
        ok = false;
      }
    }
    if (cnt == 1 && ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}