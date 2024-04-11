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
    vector<int> cnt(40, 0);
    for (int j = 0; j < n; j++){
      int cnt2 = 0;
      while (a[j] > 0){
        cnt2++;
        a[j] /= 2;
      }
      cnt[cnt2]++;
    }
    long long ans = 0;
    for (int j = 0; j < 40; j++){
      ans += (long long) cnt[j] * (cnt[j] - 1) / 2;
    }
    cout << ans << endl;
  }
}