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
    int mn = 100;
    for (int j = 0; j < n; j++){
      mn = min(mn, a[j]);
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (a[j] != mn){
        ans++;
      }
    }
    cout << ans << endl;
  }
}