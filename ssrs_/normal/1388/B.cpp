#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> r(n * 4);
    for (int j = 0; j < n * 4; j++){
      if (j >= n * 3 || j % 4 == 1 || j % 4 == 2){
        r[j] = 0;
      } else {
        r[j] = 1;
      }
    }
    for (int j = 0; j < n; j++){
      cout << max(r[j * 4] * 8 + r[j * 4 + 1] * 4 + r[j * 4 + 2] * 2 + r[j * 4 + 3], 8);
    }
    cout << endl;
  }
}