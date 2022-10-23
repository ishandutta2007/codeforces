#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n + 1, 1);
    for (int j = 0; j < n; j++){
      b[j] = lcm(b[j], a[j]);
      b[j + 1] = lcm(b[j + 1], a[j]);
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (gcd(b[j], b[j + 1]) != a[j]){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}