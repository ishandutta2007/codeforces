#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, H;
    cin >> n >> H;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int mx1 = 0, mx2 = 0;
    for (int j = 0; j < n; j++){
      if (a[j] > mx1){
        mx2 = mx1;
        mx1 = a[j];
      } else if (a[j] > mx2){
        mx2 = a[j];
      }
    }
    int q = H / (mx1 + mx2);
    int r = H % (mx1 + mx2);
    if (r == 0){
      cout << q * 2 << "\n";
    } else if (r <= mx1){
      cout << q * 2 + 1 << "\n";
    } else {
      cout << q * 2 + 2 << "\n";
    }
  }
}