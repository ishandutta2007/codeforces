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
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (a[j] == 1){
        p.push_back(j);
      }
    }
    int sz = p.size();
    if (sz % 2 == 1){
      cout << "NO" << endl;
    } else {
      vector<int> b;
      for (int j = 0; j < sz; j += 2){
        int d = p[j + 1] - p[j];
        if (d % 2 == 0){
          for (int k = p[j]; k < p[j + 1] - 2; k += 2){
            b.push_back(k);
          }
          b.push_back(p[j + 1] - 2);
          for (int k = p[j + 1] - 4; k >= p[j]; k -= 2){
            b.push_back(k);
          }
          a[p[j]] = 0;
          a[p[j + 1]] = 0;
        } else {
          for (int k = p[j]; k <= p[j + 1] - 3; k += 2){
            b.push_back(k);
            a[k + 1] = 1;
            a[k + 2] = 1;
          }
        }
      }
      for (int j = 0; j < n - 2; j++){
        if (a[j] == 0 && a[j + 1] == 1 && a[j + 2] == 1){
          b.push_back(j);
          a[j + 1] = 0;
          a[j + 2] = 0;
        }
      }
      for (int j = n - 3; j >= 0; j--){
        if (a[j] == 1 && a[j + 1] == 1 && a[j + 2] == 0){
          b.push_back(j);
          a[j] = 0;
          a[j + 1] = 0;
        }
      }
      bool ok = true;
      for (int j = 0; j < n; j++){
        if (a[j] == 1){
          ok = false;
        }
      }
      if (!ok){
        cout << "NO" << endl;
      } else {
        int k = b.size();
        cout << "YES" << endl;
        cout << k << endl;
        for (int j = 0; j < k; j++){
          cout << b[j] + 1;
          if (j < k - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}