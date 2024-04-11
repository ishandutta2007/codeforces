#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0 ; i < t; i++){
    int n, a, b;
    cin >> n >> a >> b;
    if (a > n / 2 + 1 || b < n / 2){
      cout << -1 << endl;
    } else {
      vector<bool> used(n, false);
      vector<int> p;
      p.push_back(a);
      used[a - 1] = true;
      for (int j = n; j > a; j--){
        if (p.size() == n / 2){
          break;
        }
        if (j != b){
          p.push_back(j);
          used[j - 1] = true;
        }
      }
      bool ok = true;
      if (p.size() != n / 2){
        ok = false;
      }
      for (int j = 0; j < n; j++){
        if (!used[j]){
          p.push_back(j + 1);
          if (j + 1 > b){
            ok = false;
          }
        }
      }
      if (!ok){
        cout << -1 << endl;
      } else {
        for (int j = 0; j < n; j++){
          cout << p[j];
          if (j < n - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}