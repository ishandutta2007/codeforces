#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = 0;
    int mn = a[0] - x, mx = a[0] + x;
    for (int j = 1; j < n; j++){
      mn = max(mn, a[j] - x);
      mx = min(mx, a[j] + x);
      if (mn > mx){
        ans++;
        mn = a[j] - x;
        mx = a[j] + x;
      }
    }
    cout << ans << endl;
  }
}