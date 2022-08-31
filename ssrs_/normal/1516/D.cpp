#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> prime(100001);
  for (int i = 1; i <= 100000; i++){
    prime[i] = i;
  }
  for (int i = 2; i <= 100000; i++){
    if (prime[i] == i){
      for (int j = i * 2; j <= 100000; j += i){
        prime[j] = i;
      }
    }
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> pos(100001);
  for (int i = 0; i < n; i++){
    while (a[i] > 1){
      int p = prime[a[i]];
      pos[p].push_back(i);
      while (a[i] % p == 0){
        a[i] /= p;
      }
    }
  }
  vector<int> R(n, n);
  for (int i = 2; i <= 100000; i++){
    int cnt = pos[i].size();
    for (int j = 0; j < cnt - 1; j++){
      R[pos[i][j]] = min(R[pos[i][j]], pos[i][j + 1]);
    }
  }
  for (int i = n - 1; i >= 1; i--){
    R[i - 1] = min(R[i - 1], R[i]);
  }
  vector<vector<int>> bl(LOG, vector<int>(n + 1, n));
  for (int i = 0; i < n; i++){
    bl[0][i] = R[i];
  }
  for (int i = 0; i < LOG - 1; i++){
    for (int j = 0; j < n; j++){
      bl[i + 1][j] = bl[i][bl[i][j]];
    }
  }
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    int ans = 0;
    for (int j = LOG - 1; j >= 0; j--){
      if (bl[j][l] < r){
        ans += 1 << j;
        l = bl[j][l];
      }
    }
    ans++;
    cout << ans << "\n";
  }
}