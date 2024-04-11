#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d == b * c){
      cout << 0 <<endl;
    } else if (a == 0 || c == 0){
      cout << 1 << endl;
    } else if ((a * d) % (b * c) == 0){
      cout << 1 << endl;
    } else if ((b * c) % (a * d) == 0){
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}