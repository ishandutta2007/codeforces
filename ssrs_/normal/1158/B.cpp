#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  int m = (n - k) / 2 + 1;
  for (int i = 0; i < n; i++){
    if (i % m == m - 1){
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}