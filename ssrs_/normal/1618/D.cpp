#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int j = 0; j < n - k * 2; j++){
      ans += a[j];
    }
    for (int j = n - k * 2; j < n - k; j++){
      if (a[j] == a[j + k]){
        ans++;
      }
    }
    cout << ans << endl;
  }
}