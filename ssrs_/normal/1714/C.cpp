#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int s;
    cin >> s;
    string ans;
    for (int j = 9; j >= 1; j--){
      if (s >= j){
        ans += (char) ('0' + j);
        s -= j;
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}