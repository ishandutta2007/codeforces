#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for (int j = 0; j < n; j++){
      cin >> S[j];
    }
    if (S[0][0] == '1'){
      cout << -1 << endl;
    } else {
      vector<int> u, d, l, r;
      int q = 0;
      for (int j = 0; j < n; j++){
        for (int k = m - 1; k >= 1; k--){
          if (S[j][k] == '1'){
            u.push_back(j);
            d.push_back(j);
            l.push_back(k - 1);
            r.push_back(k);
            q++;
          }
        }
      }
      for (int j = n - 1; j >= 1; j--){
        if (S[j][0] == '1'){
          u.push_back(j - 1);
          d.push_back(j);
          l.push_back(0);
          r.push_back(0);
          q++;
        }
      }
      cout << q << endl;
      for (int j = 0; j < q; j++){
        cout << u[j] + 1 << ' ' << l[j] + 1 << ' ' << d[j] + 1 << ' ' << r[j] + 1 << endl;
      }
    }
  }
}