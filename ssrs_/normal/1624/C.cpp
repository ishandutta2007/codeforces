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
      while (a[j] > n){
        a[j] /= 2;
      }
    }
    bool ok = true;
    for (int j = n; j >= 1; j--){
      vector<int> p;
      for (int k = 0; k < n; k++){
        if (a[k] == j){
          p.push_back(k);
        }
      }
      if (p.empty()){
        ok = false;
        break;
      } else {
        int cnt = p.size();
        for (int k = 1; k < cnt; k++){
          a[p[k]] /= 2;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}