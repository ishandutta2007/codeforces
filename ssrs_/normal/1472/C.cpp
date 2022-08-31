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
    vector<int> s(n);
    for (int j = n - 1; j >= 0; j--){
      if (a[j] + j >= n){
        s[j] = a[j] + j;
      } else {
        s[j] = s[a[j] + j];
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      ans = max(ans, s[j] - j);
    }
    cout << ans << endl;
  }
}