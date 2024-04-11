#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x, y, z;
  cin >> x >> y >> z;
  long long S = (x + y) / z;
  if (x / z + y / z == S){
    cout << S << ' ' << 0 << endl;
  } else {
    cout << S << ' ' << min((z - x % z) % z, (z - y % z) % z) << endl;
  }
}