#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int LOG = 20;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<int, vector<int>> dp1;
  vector<int> start(1 << LOG, 0);
  start[0] = 1;
  dp1[0] = start;
  vector<long long> dp2(n + 1, 0);
  dp2[0] = 1;
  for (int i = 0; i < n; i++){
    auto itr = dp1.end();
    itr--;
    if ((*itr).second[a[i]] == 0){
      vector<int> tmp = (*itr).second;
      for (int j = 0; j < (1 << LOG); j++){
        if (tmp[j]){
          tmp[a[i] ^ j] = 1;
        }
      }
      dp1[i + 1] = tmp;
      dp2[i + 1] = dp2[i];
    } else {
      dp2[i + 1] = dp2[i] * 2 % MOD;
    }
  }
  int C = dp1.size();
  for (int i = 0; i < q; i++){
    int l, x;
    cin >> l >> x;
    auto itr = dp1.upper_bound(l);
    itr--;
    if ((*itr).second[x] == 0){
      cout << 0 << endl;
    } else {
      cout << dp2[l] << endl;
    }
  }
}