#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> cnt(101, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int ans = 0;
    for (int j = 0; j <= 100; j++){
      ans += min(cnt[j], c);
    }
    cout << ans << endl;
  }
}