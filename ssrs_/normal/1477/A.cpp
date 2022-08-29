#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    long long g = 0;
    for (int j = 1; j < n; j++){
      g = gcd(g, abs(x[j] - x[0]));
    }
    if (g == 0){
      if (k == x[0]){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if ((k - x[0]) % g == 0){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}