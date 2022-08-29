#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    int mx = h[0], mn = h[0];
    bool ok = true;
    for (int j = 1; j < n; j++){
      if (mx <= h[j] - k){
        ok = false;
      } else if (mn >= h[j] + k * 2){
        ok = false;
      } else {
        mn = max(mn - (k - 1), h[j]);
        mx = min(mx + (k - 1), h[j] + k - 1);
        if (mn > mx){
          ok = false;
        }
      }
    }
    if (!(mn <= h[n - 1] && h[n - 1] <= mx)){
      ok = false;
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}