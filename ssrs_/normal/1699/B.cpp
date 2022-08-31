#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cout << ((j + 1) / 2 + (k + 1) / 2) % 2;
        if (k < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}