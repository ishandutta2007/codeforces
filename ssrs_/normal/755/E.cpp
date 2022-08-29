#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  if (n <= 3){
    cout << -1 << endl;
  } else if (k == 1){
    cout << -1 << endl;
  } else if (k >= 4){
    cout << -1 << endl;
  } else if (k == 2){
    if (n == 4){
      cout << -1 << endl;
    } else {
      cout << n * 2 - 4 << endl;
      cout << 1 << ' ' << 2 << endl;
      cout << 2 << ' ' << 3 << endl;
      cout << 3 << ' ' << 4 << endl;
      cout << 1 << ' ' << 4 << endl;
      for (int i = 5; i <= n; i++){
        cout << 1 << ' ' << i << endl;
        cout << 4 << ' ' << i << endl;
      }
    }
  } else {
    cout << n - 1 << endl;
    cout << 1 << ' ' << 2 << endl;
    cout << 1 << ' ' << 3 << endl;
    for (int i = 4; i <= n; i++){
      cout << 2 << ' ' << i << endl;
    }
  }
}