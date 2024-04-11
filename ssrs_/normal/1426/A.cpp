#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    if (n <= 2){
      cout << 1 << endl;
    } else {
      cout << (n - 3) / x + 2 << endl;
    }
  }
}