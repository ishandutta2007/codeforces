#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 3 == 0){
      cout << n / 3 << endl;
    } else if (n % 3 == 1){
      cout << max(2, n / 3 + 1) << endl;
    } else {
      cout << n / 3 + 1 << endl;
    }
  }
}