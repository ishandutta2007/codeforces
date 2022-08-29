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
    bool ok = true;
    long long P = 1;
    for (int j = 0; j < n; j++){
      P = lcm(P, j + 2);
      if (a[j] % P == 0){
        ok = false;
      }
      if (P > 1000000000){
        break;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}