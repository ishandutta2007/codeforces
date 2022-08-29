#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    sx--;
    sy--;
    bool ok = false;
    if (sx > d && m - 1 - sy > d){
      ok = true;
    }
    if (sy > d && n - 1 - sx > d){
      ok = true;
    }
    if (ok){
      cout << n + m - 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}