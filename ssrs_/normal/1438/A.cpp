#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    for (int j = 0; j < n; j++){
      cout << 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}