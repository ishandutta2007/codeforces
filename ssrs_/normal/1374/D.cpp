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
      a[j] = (k - a[j] % k) % k;
    }
    map<int, int> cnt;
    for (int j = 0; j < n; j++){
      if (a[j] != 0){
        cnt[a[j]]++;
      }
    }
    long long ans = 0;
    for (auto P : cnt){
      ans = max(ans, (long long) (P.second - 1) * k + P.first + 1);
    }
    cout << ans << endl;
  }
}