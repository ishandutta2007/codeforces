#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int j = 0; j < n; j++){
      cin >> x[j] >> y[j];
    }
    int mnx = 0, mxx = 0, mny = 0, mxy = 0;
    for (int j = 0; j < n; j++){
      mnx = min(mnx, x[j]);
      mxx = max(mxx, x[j]);
      mny = min(mny, y[j]);
      mxy = max(mxy, y[j]);
    }
    cout << (mxx - mnx) * 2 + (mxy - mny) * 2 << endl;
  }
}