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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    int mx = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, a[j] - b[j]);
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (b[j] != max(a[j] - mx, 0)){
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