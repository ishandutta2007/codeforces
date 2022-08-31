#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    bool inc = false;
    bool dec = false;
    int J = -1;
    for (int j = 0; j < n - 1; j++){
      if (p[j] < p[j + 1]){
        inc = true;
      } else {
        dec = true;
        if (inc){
          J = j;
          break;
        }
      }
    }
    if (J == -1){
      cout << "NO" << endl;
    } else {
      int I = J - 1;
      while (p[J] < p[I]){
        I--;
      }
      cout << "YES" << endl;
      cout << I + 1 << ' ' << J + 1 << ' ' << J + 2 << endl;
    }
  }
}