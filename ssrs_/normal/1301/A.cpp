#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string a,b,c;
    cin >> a >> b >> c;
    bool ans = true;
    int n = a.size();
    for (int j = 0; j < n; j++){
      if (a[j] != c[j] && b[j] != c[j]){
        ans = false;
      }
    }
    if (ans){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}