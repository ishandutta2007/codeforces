#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    cout << 100 / gcd(100, k) << endl;
  }
}