#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int r, g, b;
    cin >> r >> g >> b;
    int s = (r + g + b) / 2;
    cout << min({s, r + g, g + b, b + r}) << endl;
  }
}