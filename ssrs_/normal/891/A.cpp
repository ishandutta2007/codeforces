#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int G = a[0];
  for (int i = 1; i < n; i++){
    G = gcd(G, a[i]);
  }
  if (G > 1){
    cout << -1 << endl;
  } else {
    int one = 0;
    for (int i = 0; i < n; i++){
      if (a[i] == 1){
        one++;
      }
    }
    if (one != 0){
      cout << n - one << endl;
    } else {
      vector<vector<int>> r(n, vector<int>(n)); //range gcd
      for (int i = 0; i < n; i++){
        r[i][i] = a[i];
        for (int j = i + 1; j < n; j++){
          r[i][j] = gcd(r[i][j - 1], a[j]);
        }
      }
      bool flg = true;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i; j++){
          if (r[j][j + i] == 1 && flg){
            cout << n + i - 1 << endl;
            flg = false;
          }
        }
      }
    }
  }
}