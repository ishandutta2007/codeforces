#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  vector<int> good;
  for (int x = 1; x <= 5000; x++){
    vector<int> b = a;
    for (int i = 0; i < n; i++){
      b[i] -= x;
      b[i] = max(b[i], 0);
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++){
      c[i] = n - b[i] - i;
    }
    bool ok = true;
    for (int i = 0; i < n; i++){
      if (c[i] <= 0){
        ok = false;
      }
    }
    if (ok){
      bool ok2 = true;
      for (int i = 0; i < n; i++){
        if (c[i] % p == 0){
          ok2 = false;
        }
      }
      if (ok2){
        good.push_back(x);
      }
    }
  }
  int cnt = good.size();
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++){
    cout << good[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}