#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x, y, k;
    cin >> x >> y >> k;
    cout << ((y + 1) * k - 1 + x - 2) / (x - 1) + k << endl;
  }
}