#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mx = 0;
  for (int i = 0; i < n; i++){
    mx = max(mx, a[i]);
  }
  int z = 0;
  for (int i = 0; i < n; i++){
    z = gcd(z, mx - a[i]);
  }
  long long y = 0;
  for (int i = 0; i < n; i++){
    y += (mx - a[i]) / z;
  }
  cout << y << ' ' << z << endl;
}