#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int j = 0; j < n; j++){
      int pos = 0, neg = 0, con = 0;
      for (int k = j; k < n; k++){
        if (s[k] == '+'){
          pos++;
        }
        if (s[k] == '-'){
          neg++;
          if (k > j){
            if (s[k - 1] == '-'){
              con++;
            }
          }
        }
        if (pos <= neg){
          if ((neg - pos) % 3 == 0 && (neg - pos) / 3 <= con){
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
}