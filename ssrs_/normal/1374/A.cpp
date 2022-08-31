#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, y, n;
    cin >> x >> y >> n;
    cout << (n - y) / x * x + y << endl;
  }
}