#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 7 == 0){
      cout << n << endl;
    } else {
      for (int j = 0; j < 10; j++){
        int x = n - n % 10 + j;
        if (x % 7 == 0){
          cout << x << endl;
          break;
        }
      }
    }
  }
}