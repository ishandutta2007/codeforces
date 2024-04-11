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
    vector<bool> used(n, false);
    vector<int> b(n);
    vector<int> c(n);
    int id = 0;
    for (int j = 1; j < n; j++){
      if (a[j] > a[id]){
        id = j;
      }
    }
    used[id] = true;
    b[0] = a[id];
    c[0] = a[id];
    for (int j = 1; j < n; j++){
      int next = -1;
      for (int k = 0; k < n; k++){
        if (!used[k]){
          if (next == -1){
            next = k;
          } else if (gcd(c[j - 1], a[k]) > gcd(c[j - 1], a[next])){
            next = k;
          }
        }
      }
      b[j] = a[next];
      c[j] = gcd(c[j - 1], b[j]);
      used[next] = true;
    }
    for (int j = 0; j < n; j++){
      cout << b[j];
      if (j < n - 1){
        cout << ' ' ;
      }
    }
    cout << endl;
  }
}