#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    int mx = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, b[j]);
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += a[j] + b[j];
    }
    cout << ans - mx << endl;
  }
}