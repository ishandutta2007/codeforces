#include <bits/stdc++.h>
using  namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++){
    if (a[i] != 0){
      pos[a[i] - 1] = i;
    }
  }
  for (int i = 0; i < n; i++){
    if (b[i] != 0){
      pos[b[i] - 1] = n + i;
    }
  }
  if (pos[0] < n){
    int m = 0;
    for (int i = 1; i < n; i++){
      if (pos[i] >= n){
        m = max(m, pos[i] + 1 - n - i);
      }
    }
    cout << n + m << endl;
  } else {
    bool s = true;
    for (int i = pos[0] - n; i < n; i++){
      if (b[i] != i - (pos[0] - n) + 1){
        s = false;
      }
    }
    int st = n * 2 - pos[0];
    for (int i = (n * 2 - pos[0]); i < n; i++){
      if (pos[i] >= n){
        if (pos[i] - n - (i - st) >= 0){
          s = false;
        }
      }
    }
    if (s){
      cout << n - st << endl;
    } else {
      int m = 0;
      for (int i = 0; i < n; i++){
        if (pos[i] >= n){
          m = max(m, pos[i] - n - i);
        }
      }
      cout << n + m + 1 << endl;
    }
  }
}