#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
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
    int mn = INF;
    for (int j = 0; j < n; j++){
      mn = min(mn, a[j]);
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      ans += a[j] - mn;
    }
    cout << ans << endl;
  }
}