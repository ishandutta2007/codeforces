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
    vector<int> s(n);
    s[0] = 0;
    for (int j = 0; j < n - 1; j++){
      s[j + 1] = s[j];
      if (a[j] >= a[j + 1] * 2){
        s[j + 1]++;
      }
    }
    int ans = 0;
    for (int j = 0; j < n - k; j++){
      if (s[j + k] - s[j] == 0){
        ans++;
      }
    }
    cout << ans << endl;
  }
}