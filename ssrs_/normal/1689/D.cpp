#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
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
    int smax = -INF, smin = INF, dmax = -INF, dmin = INF;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (S[j][k] == 'B'){
          smax = max(smax, j + k);
          smin = min(smin, j + k);
          dmax = max(dmax, j - k);
          dmin = min(dmin, j - k);
        }
      }
    }
    int x = 0, y = 0, ans = INF;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        int mx = 0;
        mx = max(mx, smax - (j + k));
        mx = max(mx, (j + k) - smin);
        mx = max(mx, dmax - (j - k));
        mx = max(mx, (j - k) - dmin);
        if (mx < ans){
          ans = mx;
          x = j;
          y = k;
        }
      }
    }
    cout << x + 1 << ' ' << y + 1 << endl;
  }
}