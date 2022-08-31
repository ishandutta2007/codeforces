#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int j = 0; j < q; j++){
      int l, r;
      cin >> l >> r;
      l--;
      bool ok = false;
      for (int k = 0; k < l; k++){
        if (s[k] == s[l]){
          ok = true;
        }
      }
      for (int k = r; k < n; k++){
        if (s[k] == s[r - 1]){
          ok = true;
        }
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}