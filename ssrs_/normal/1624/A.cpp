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
    int mx = a[0], mn = a[0];
    for (int j = 1; j < n; j++){
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
    }
    cout << mx - mn << endl;
  }
}