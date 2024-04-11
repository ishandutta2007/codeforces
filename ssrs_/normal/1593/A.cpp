#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    int A = max({b - a + 1, c - a + 1, 0});
    int B = max({c - b + 1, a - b + 1, 0});
    int C = max({a - c + 1, b - c + 1, 0});
    cout << A << ' ' << B << ' ' << C << endl;
  }
}