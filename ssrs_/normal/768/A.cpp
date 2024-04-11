#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mn = INF, mx = 0;
  for (int i = 0; i < n; i++){
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (mn < a[i] && a[i] < mx){
      ans++;
    }
  }
  cout << ans << endl;
}