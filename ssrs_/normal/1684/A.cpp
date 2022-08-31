#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string n;
    cin >> n;
    int L = n.size();
    if (L == 2){
      cout << n[1] << endl;
    } else {
      int ans = 9;
      for (int j = 0; j < L; j++){
        ans = min(ans, n[j] - '0');
      }
      cout << ans << endl;
    }
  }
}