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
    bool res = true;
    for (int j = 1; j < n; j++){
      if (a[j] % 2 != a[0] % 2){
        res = false;
      }
    }
    if (res){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}