#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int a, b, c;
  cin >> a >> b >> c;
  if (a >= x && a + b >= x + y && a + b + c >= x + y + z){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}