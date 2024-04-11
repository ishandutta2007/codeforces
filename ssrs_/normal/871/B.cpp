#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1), x(n - 1);
  for (int i = 0; i < n - 1; i++){
    cout << "? " << i << ' ' << i << endl;
    cin >> a[i];
    cout << "? " << i + 1 << ' ' << i << endl;
    cin >> b[i];
    x[i] = a[i] ^ b[i];
  }
  vector<int> ans;
  int anscnt = 0;
  for (int i = 0; i < n; i++){
    vector<int> p(n);
    p[0] = i;
    for (int j = 0; j < n - 1; j++){
      p[j + 1] = p[j] ^ x[j];
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (p[j] >= n){
        ok = false;
        break;
      }
    }
    if (ok){
      vector<int> q(n, -1);
      for (int j = 0; j < n; j++){
        if (q[p[j]] != -1){
          ok = false;
          break;
        }
        q[p[j]] = j;
      }
      if (ok){
        for (int j = 0; j < n - 1; j++){
          if ((p[j] ^ q[j]) != a[j]){
            ok = false;
            break;
          }
          if ((p[j + 1] ^ q[j]) != b[j]){
            ok = false;
            break;
          }
        }
        if (ok){
          ans = p;
          anscnt++;
        }
      }
    }
  }
  cout << "!" << endl;
  cout << anscnt << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}