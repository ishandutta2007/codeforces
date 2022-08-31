#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, y;
    cin >> x >> y;
    cout << max({x + y, x * 2 - 1, y * 2 - 1}) << endl;
  }
}