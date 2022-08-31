#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    if (n < 3){
      cout << -1 << endl;
    } else if (n == 5 || n == 7 || n == 11){
      cout << -1 << endl;
    } else {
      if (n % 4 == 0){
        cout << n / 4 << endl;
      }
      if (n % 4 == 1){
        cout << (n - 5) / 4 << endl;
      }
      if (n % 4 == 2){
        cout << (n - 2) / 4 << endl;
      }
      if (n % 4 == 3){
        cout << (n - 7) / 4 << endl;
      }
    }
  }
}