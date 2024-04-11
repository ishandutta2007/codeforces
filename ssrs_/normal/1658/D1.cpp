#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    vector<int> a(r + 1);
    for (int j = 0; j <= r; j++){
      cin >> a[j];
    }
    int x = 0;
    for (int j = 0; j < 17; j++){
      int cnt0 = 0, cnt1 = 0;
      for (int k = 0; k <= r; k++){
        if ((a[k] >> j & 1) == 0){
          cnt0++;
        } else {
          cnt1++;
        }
      }
      if (cnt1 > cnt0){
        x |= 1 << j;
      }
    }
    cout << x << endl;
  }
}