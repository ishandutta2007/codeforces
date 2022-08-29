#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 2 == 1){
      cout << -1 << endl;
    } else {
      cout << 0 << ' ' << n / 2 << ' ' << n / 2 << endl;
    }
  }
}