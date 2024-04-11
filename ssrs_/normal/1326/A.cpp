#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << -1;
    } else {
      cout << 2;
      for (int i = 1; i < n - 1; i++){
        cout << 6;
      }
      cout << 3;
    }
    cout << endl;
  }
}