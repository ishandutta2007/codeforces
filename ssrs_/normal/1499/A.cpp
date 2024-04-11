#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w, b;
    cin >> w >> b;
    if (k1 + k2 >= w * 2 && (n - k1) + (n - k2) >= b * 2){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}