#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  vector<int> cnt(k, 0);
  for (int i = 0; i < n; i++){
    cnt[d[i] % k]++;
  }
  int ans = 0;
  for (int i = 0; i < k; i++){
    int j = (k - i) % k;
    if (i < j){
      ans += min(cnt[i], cnt[j]) * 2;
    } else if (i == j){
      ans += cnt[i] / 2 * 2;
    }
  }
  cout << ans << endl;
}