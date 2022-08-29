#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    int x = 0;
    for (int j = a / 4 * 4; j < a; j++){
      x ^= j;
    }
    if (x == b){
      cout << a << endl;
    } else if (x != (a ^ b)){
      cout << a + 1 << endl;
    } else {
      cout << a + 2 << endl;
    }
  }
}