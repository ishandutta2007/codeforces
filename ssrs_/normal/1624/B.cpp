#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if (b * 2 - c > 0 && (b * 2 - c) % a == 0){
      cout << "YES" << endl;
    } else if (b * 2 - a > 0 && (b * 2 - a) % c == 0){
      cout << "YES" << endl;
    } else if ((a + c) % 2 == 0 && (a + c) / 2 % b == 0){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}