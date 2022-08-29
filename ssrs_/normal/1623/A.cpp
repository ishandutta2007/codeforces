#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    rb--;
    cb--;
    rd--;
    cd--;
    int dr = 1, dc = 1;
    int cnt = 0;
    while (true){
      if (rb == rd || cb == cd){
        cout << cnt << endl;
        break;
      }
      if (rb == n - 1){
        dr = -1;
      }
      if (rb == 0){
        dr = 1;
      }
      if (cb == m - 1){
        dc = -1;
      }
      if (cb == 0){
        dc = 1;
      }
      rb += dr;
      cb += dc;
      cnt++;
    }
  }
}