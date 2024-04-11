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
        if (j == 0 || k == 0){
          cout << 'B';
        } else {
          cout << 'W';
        }
      }
      cout << endl;
    }
  }
}