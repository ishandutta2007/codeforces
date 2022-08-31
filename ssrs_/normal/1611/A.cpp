#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string n;
    cin >> n;
    int l = n.size();
    if ((n[l - 1] - '0') % 2 == 0){
      cout << 0 << endl;
    } else if ((n[0] - '0') % 2 == 0){
      cout << 1 << endl;
    } else {
      int ans = -1;
      for (int j = 0; j < l; j++){
        if ((n[j] - '0') % 2 == 0){
          ans = 2;
        }
      }
      cout << ans << endl;
    }
  }
}