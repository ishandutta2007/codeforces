#include <bits/stdc++.h>
using namespace std;
long long mod(long long a, long long b){
  return (a % b + b) % b;
}
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (n == 1){
    cout << 1 << ' ' << 1 << endl;
    cout << - a[0] << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 0 << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 0 << endl;
  } else {
    cout << 1 << ' ' << n - 1 << endl;
    for (int i = 0; i < n - 1; i++){
      long long r = mod(a[i], n);
      a[i] += (n - 1) * r;
      cout << (n - 1) * r;
      if (i < n - 2){
        cout << ' ';
      }
    }
    cout << endl;
    cout << 2 << ' ' << n << endl;
    for (int i = 1; i < n; i++){
      long long r = mod(a[i], n);
      a[i] += (n - 1) * r;
      cout << (n - 1) * r;
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
    cout << 1 << ' ' << n << endl;
    for (int i = 0; i < n; i++){
      cout << - a[i];
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}