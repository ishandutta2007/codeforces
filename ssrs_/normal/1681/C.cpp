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
    int k = 0;
    vector<int> x, y;
    for (int j = 0; j < n; j++){
      for (int l = 0; l < n - 1; l++){
        if (make_pair(a[l], b[l]) > make_pair(a[l + 1], b[l + 1])){
          swap(a[l], a[l + 1]);
          swap(b[l], b[l + 1]);
          k++;
          x.push_back(l);
          y.push_back(l + 1);
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < n - 1; j++){
      if (b[j] > b[j + 1]){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << x[j] + 1 << ' ' << y[j] + 1 << endl;
      }
    }
  }
}