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
    int neg = 0;
    for (int j = 0; j < n; j++){
      if (a[j] < 0){
        neg++;
      }
    }
    for (int j = 0; j < neg; j++){
      a[j] = -abs(a[j]);
    }
    for (int j = neg; j < n; j++){
      a[j] = abs(a[j]);
    }
    bool ok = true;
    for (int j = 0; j < n - 1; j++){
      if (a[j] > a[j + 1]){
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