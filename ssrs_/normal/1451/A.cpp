#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << 0 << endl;
    } else if (n == 2){
      cout << 1 << endl;
    } else if (n == 3){
      cout << 2 << endl;
    } else if (n % 2 == 0){
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
}