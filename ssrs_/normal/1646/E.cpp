#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> mx(n + 1, 1);
  vector<bool> ok(n + 1, true);
  for (int i = 2; i * i <= n; i++){
    long long P = i;
    while (true){
      P *= i;
      if (P > n){
        break;
      }
      ok[P] = false;
      mx[i]++;
    }
  }
  vector<bool> used(m * 20 + 1, false);
  vector<int> cnt(21, 0);
  int c = 0;
  for (int i = 1; i <= 20; i++){
    for (int j = 1; j <= m; j++){
      if (!used[i * j]){
        used[i * j] = true;
        c++;
      }
    }
    cnt[i] = c;
  }
  long long ans = 1;
  for (int i = 2; i <= n; i++){
    if (ok[i]){
      ans += cnt[mx[i]];
    }
  }
  cout << ans << endl;
}