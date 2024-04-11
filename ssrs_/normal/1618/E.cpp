#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    long long s = 0;
    for (int j = 0; j < n; j++){
      s += b[j];
    }
    if (s % (n * (n + 1) / 2) != 0){
      cout << "NO" << endl;
    } else {
      s /= n * (n + 1) / 2;
      vector<long long> a(n);
      bool ok = true;
      for (int j = 0; j < n; j++){
        int d = b[j] - b[(j + n - 1) % n];
        if ((s - d) % n != 0){
          ok = false;
        } else {
          a[j] = (s - d) / n;
          if (a[j] <= 0 || a[j] > 1000000000){
            ok = false;
          }
        }
      }
      if (!ok){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for (int j = 0; j < n; j++){
          cout << a[j];
          if (j < n - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}