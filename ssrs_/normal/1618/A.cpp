#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<int> b(7);
    for (int j = 0; j < 7; j++){
      cin >> b[j];
    }
    cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[0] - b[1] << endl;
  }
}