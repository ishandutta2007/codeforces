#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    vector<int> cnt(r + 1, 0);
    for (int j = l; j <= r; j++){
      for (int k = j * 2; k <= r; k += j){
        cnt[k]++;
      }
    }
    long long ans = 0;
    for (int j = l; j <= r; j++){
      ans += cnt[j] * (cnt[j] - 1) / 2;
    }
    for (int j = l; j <= r; j++){
      if (j % 6 == 0 && j / 2 >= l){
        ans++;
      }
      if (j % 15 == 0 && j / 5 * 2 >= l){
        ans++;
      }
    }
    long long sum = (long long) (r - l + 1) * (r - l) * (r - l - 1) / 6;
    cout << sum - ans << endl;
  }
}