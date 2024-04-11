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
    long long ans = 0;
    long long p = a[0];
    for (int j = 0; j < n - 1; j++){
      if (a[j] < a[j + 1]){
        ans += a[j + 1] - a[j];
      } else {
        ans += a[j] - a[j + 1];
        p -= a[j] - a[j + 1];
      }
    }
    ans += abs(p);
    cout << ans << endl;
  }
}