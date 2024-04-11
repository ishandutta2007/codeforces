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
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool ok = true;
    if (n % 2 == 1){
      if (a[0] != b[0]){
        ok = false;
      }
    }
    for (int j = n % 2; j < n; j += 2){
      if (!(a[j] == b[j] && a[j + 1] == b[j + 1] || a[j] == b[j + 1] && a[j + 1] == b[j])){
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