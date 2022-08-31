#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string A;
    cin >> A;
    string B;
    cin >> B;
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (B[j] < A[j]){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      int ans = 0;
      for (int j = 0; j < 20; j++){
        char mx = 'z';
        vector<int> pos;
        for (int k = 0; k < n; k++){
          if (A[k] == 'a' + j && A[k] != B[k]){
            mx = min(mx, B[k]);
            pos.push_back(k);
          }
        }
        if (mx != 'z'){
          ans++;
          for (int k : pos){
            A[k] = mx;
          }
        }
      }
      cout << ans << endl;
    }
  }
}