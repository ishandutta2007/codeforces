#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    int mx = -INF;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        mx = max(mx, a[j][k]);
      }
    }
    int x, y;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (a[j][k] == mx){
          x = j;
          y = k;
        }
      }
    }
    int h = max(x + 1, n - x);
    int w = max(y + 1, m - y);
    cout << h * w << endl;
  }
}