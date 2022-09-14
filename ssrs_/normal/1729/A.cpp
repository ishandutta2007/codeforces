#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    int x = a - 1;
    int y = abs(c - b) + (c - 1);
    if (x < y){
      cout << 1 << endl;
    } else if (x > y){
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
}