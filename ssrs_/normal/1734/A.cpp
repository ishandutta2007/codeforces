#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
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
    sort(a.begin(), a.end());
    int ans = INF;
    for (int j = 0; j < n - 2; j++){
      ans = min(ans, a[j + 2] - a[j]);
    }
    cout << ans << endl;
  }
}