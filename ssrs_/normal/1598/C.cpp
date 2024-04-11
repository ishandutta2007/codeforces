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
    long long S = 0;
    for (int j = 0; j < n; j++){
      S += a[j];
    }
    S *= 2;
    if (S % n != 0){
      cout << 0 << endl;
    } else {
      long long T = S / n;
      map<int, int> mp;
      long long ans = 0;
      for (int j = 0; j < n; j++){
        if (mp.count(T - a[j]) == 1){
          ans += mp[T - a[j]];
        }
        mp[a[j]]++;
      }
      cout << ans << endl;
    }
  }
}