#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    a[0] = 1;
    bool ok = true;
    for (int j = 1; j < n; j++){
      a[j] = a[j - 1] * 3;
      if (a[j] > 1000000000){
        ok = false;
        break;
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