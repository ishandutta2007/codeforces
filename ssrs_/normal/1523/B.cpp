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
    cout << n * 3 << endl;
    for (int j = 0; j < n / 2; j++){
      int a = j * 2 + 1, b = j * 2 + 2;
      cout << 1 << ' ' << a << ' ' << b << endl;
      cout << 2 << ' ' << a << ' ' << b << endl;
      cout << 1 << ' ' << a << ' ' << b << endl;
      cout << 1 << ' ' << a << ' ' << b << endl;
      cout << 2 << ' ' << a << ' ' << b << endl;
      cout << 1 << ' ' << a << ' ' << b << endl;
    }
  }
}