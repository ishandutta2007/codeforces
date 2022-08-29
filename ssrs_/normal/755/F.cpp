#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> cnt;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      int c = 1;
      int x = i;
      while (!used[p[x]]){
        x = p[x];
        used[x] = true;
        c++;
      }
      cnt.push_back(c);
    }
  }
  int m = cnt.size();
  int mx = 0;
  int r = k;
  for (int i = 0; i < m; i++){
    int p = min(r, cnt[i] / 2);
    mx += p * 2;
    r -= p;
  }
  for (int i = 0; i < m; i++){
    if (cnt[i] % 2 == 1 && r > 0){
      mx++;
      r--;
    }
  }
  vector<int> F(n + 1, 0);
  for (int i = 0; i < m; i++){
    F[cnt[i]]++;
  }
  for (int i = 1; i <= n; i++){
    if (F[i] >= 3){
      int p = (F[i] - 1) / 2;
      F[i * 2] += p;
      F[i] -= p * 2;
    }
  }
  bitset<1000001> dp;
  dp.set(0);
  for (int i = 1; i <= n; i++){
    if (F[i] == 1){
      dp |= dp << i;
    }
    if (F[i] == 2){
      dp |= (dp << i) | (dp << (i * 2));
    }
  }
  if (dp[k]){
    cout << k << ' ' << mx << endl;
  } else {
    cout << k + 1 << ' ' << mx << endl;
  }
}