#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    if (k < n){
      cout << (n + k) % 2 << endl;
    } else {
      cout << k - n << endl;
    }
  }
}