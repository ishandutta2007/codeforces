#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--;
    c--;
    for (int j = 0; j < n; j++){
      for (int l = 0; l < n; l++){
        if ((j + l) % k == (r + c) % k){
          cout << 'X';
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
  }
}