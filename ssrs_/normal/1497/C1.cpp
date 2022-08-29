#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1){
      cout << 1 << ' ' << (n - 1) / 2 << ' ' << (n - 1) / 2 << endl;
    } else if (n % 4 == 0){
      cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << endl;
    } else {
      cout << 2 << ' ' << (n - 1) / 2 << ' ' << (n - 1) / 2 << endl;
    }
  }
}