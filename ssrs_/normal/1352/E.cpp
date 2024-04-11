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
    int ans = 0;
    for (int j = 0; j < n; j++){
      bool flg = false;
      int curr = 0;
      int L = 0, R = 0;
      while (L < n){
        while (curr < a[j]){
          if (R >= n){
            break;
          }
          curr += a[R];
          R++;
          //cout << "L = " << L << ", R = " << R << ", sum = " << curr << endl;
        }
        if (curr == a[j] && R - L != 1){
          //cout << a[j] << ", L = " << L << ", R = " << R << ", curr = " << curr << endl;
          flg = true;
          break;
        }
        curr -= a[L];
        L++;
        //cout << "L = " << L << ", R = " << R << ", sum = " << curr << endl;
      }
      if (flg){
        ans++;
      }
    }
    cout << ans << endl;
  }
}