#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int id(vector<int> &A){
  int ans = 0;
  if (A[0] == 0){
    ans |= 1;
  }
  if (A[1] == 0){
    ans |= 2;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  int mx = max(n, m);
  vector<long long> POW(mx + 1);
  POW[0] = 1;
  for (int i = 0; i < mx; i++){
    POW[i + 1] = POW[i] * 2 % MOD;
  }
  map<pair<int, int>, int> mp;
  vector<vector<int>> row(m, vector<int>(2, 0));
  vector<int> row_cnt = {0, 0, 0, m};
  vector<vector<int>> col(n, vector<int>(2, 0));
  vector<int> col_cnt = {0, 0, 0, n};
  vector<int> ng(2, 0);
  for (int i = 0; i < k; i++){
    int x, y, t;
    cin >> x >> y >> t;
    x--;
    y--;
    if (mp.count(make_pair(x, y))){
      int a = mp[make_pair(x, y)];
      row_cnt[id(row[y])]--;
      row[y][(a + x) % 2]--;
      row_cnt[id(row[y])]++;
      col_cnt[id(col[x])]--;
      col[x][(a + y) % 2]--;
      col_cnt[id(col[x])]++;
      ng[(a + x + y) % 2]--;
      mp.erase(make_pair(x, y));
    }
    if (t != -1){
      row_cnt[id(row[y])]--;
      row[y][(t + x) % 2]++;
      row_cnt[id(row[y])]++;
      col_cnt[id(col[x])]--;
      col[x][(t + y) % 2]++;
      col_cnt[id(col[x])]++;
      ng[(t + x + y) % 2]++;
      mp[make_pair(x, y)] = t;
    }
    long long ans = 0;
    if (row_cnt[0] == 0){
      ans += POW[row_cnt[3]];
    }
    if (col_cnt[0] == 0){
      ans += POW[col_cnt[3]];
    }
    for (int j = 0; j < 2; j++){
      if (ng[j] == 0){
        ans += MOD - 1;
      }
    }
    ans %= MOD;
    cout << ans << "\n";
  }
}