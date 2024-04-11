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
    int s = 0;
    for (int j = 0; j < n; j++){
      s ^= a[j];
    }
    if (s == 0){
      cout << "DRAW" << endl;
    } else {
      int c = 1;
      while (c * 2 <= s){
        c *= 2;
      }
      int cnt0 = 0, cnt1 = 0;
      for (int j = 0; j < n; j++){
        if ((a[j] & c) == 0){
          cnt0++;
        } else {
          cnt1++;
        }
      }
      if (n % 2 == 0){
        cout << "WIN" << endl;
      } else if (cnt1 % 4 == 3){
        cout << "LOSE" << endl;
      } else {
        cout << "WIN" << endl;
      }
    }
  }
}