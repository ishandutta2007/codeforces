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
    vector<long long> d(n + 1, 0);
    for (int j = 0; j < n - 1; j++){
      if (a[j] > a[j + 1]){
        int c = a[j] - a[j + 1];
        d[0] += c;
        d[j + 1] -= c;
      }
      if (a[j] < a[j + 1]){
        int c = a[j + 1] - a[j];
        d[j + 1] += c;
        d[n] -= c;
      }
    }
    for (int j = 1; j <= n; j++){
      d[j] += d[j - 1];
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (a[j] < d[j]){
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