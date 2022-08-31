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
    bool res = false;
    map<int, int> M;
    for (int j = 0; j < n; j++){
      M[a[j]]++;
      if (M[a[j]] == 3){
        res = true;
      } else if (M[a[j]] == 2){
        if (a[j - 1] != a[j]){
          res = true;
        }
      }
    }
    if (res){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}