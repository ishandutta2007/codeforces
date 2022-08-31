#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    cout << 0 << endl;
    int r;
    cin >> r;
    if (r == 0){
      for (int j = 0; j < n - 1; j++){
        int y = j ^ (j + 1);
        cout << y << endl;
        cin >> r;
        if (r == 1){
          break;
        }
      }
    }
  }
}