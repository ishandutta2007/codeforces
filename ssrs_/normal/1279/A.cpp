#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long r, g, b;
    cin >> r >> g >> b;
    if (max({r, g, b}) <= (r + g + b + 1) / 2){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}