#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  if (n == 1){
    for (int i = 0; i < m; i++){
      cout << a[0] + b[i];
      if (i < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  } else {
    long long g = a[1] - a[0];
    for (int i = 2; i < n; i++){
      g = gcd(g, a[i] - a[i - 1]);
    }
    for (int i = 0; i < m; i++){
      cout << gcd(g, a[0] + b[i]);
      if (i < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}