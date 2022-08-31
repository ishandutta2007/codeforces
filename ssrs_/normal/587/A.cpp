#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  vector<int> cnt(1000030, 0);
  for (int i = 0; i < n; i++){
    cnt[w[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < 1000029; i++){
    cnt[i + 1] += cnt[i] / 2;
    cnt[i] %= 2;
    if (cnt[i] == 1){
      ans++;
    }
  }
  cout << ans << endl;
}