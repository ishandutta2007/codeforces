#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x;
    cin >> x;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1 || b == 2 || c == 3){
      cout << "NO" << endl;
    } else if (a == 2 && b == 1){
      cout << "NO" << endl;
    } else if (a == 3 && c == 1){
      cout << "NO" << endl;
    } else if (b == 3 && c == 2){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}