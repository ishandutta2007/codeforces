#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long r, b, d;
    cin >> r >> b >> d;
    if (r <= b * (d + 1) && b <= r * (d + 1)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}