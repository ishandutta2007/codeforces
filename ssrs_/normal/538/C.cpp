#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> d(m), h(m);
  for (int i = 0; i < m; i++){
    cin >> d[i] >> h[i];
  }
  bool ok = true;
  for (int i = 0; i < m - 1; i++){
    if (abs(h[i + 1] - h[i]) > abs(d[i + 1] - d[i])){
      ok = false;
    }
  }
  if (!ok){
    cout << "IMPOSSIBLE" << endl;
  } else {
    int mx = 0;
    mx = max(mx, d[0] - 1 + h[0]);
    mx = max(mx, n - d[m - 1] + h[m - 1]);
    for (int i = 0; i < m - 1; i++){
      if ((d[i + 1] - d[i]) % 2 == (h[i + 1] - h[i]) % 2){
        int tmp = (d[i + 1] - d[i] + h[i + 1] + h[i]) / 2;
        mx = max(mx, tmp);
      } else {
        int tmp = (d[i + 1] - d[i] - 1 + h[i + 1] + h[i]) / 2;
        mx = max(mx, tmp);
      }
    }
    cout << mx << endl;
  }
}