#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> id(n);
  for (int i = 0; i < m; i++){
    int s;
    cin >> s;
    for (int j = 0; j < s; j++){
      int A;
      cin >> A;
      id[A - 1] = i;
    }
  }
  vector<int> cnt(m, 0);
  for (int i = 0; i < d; i++){
    cnt[id[i]]++;
  }
  vector<int> z(1 << m, 0);
  for (int i = 0; i <= n - d; i++){
    int s = 0;
    for (int j = 0; j < m; j++){
      if (cnt[j] > 0){
        s |= 1 << j;
      }
    }
    z[(1 << m) - 1 - s]++;
    if (i < n - d){
      cnt[id[i]]--;
      cnt[id[i + d]]++;
    }
  }
  for (int i = 0; i < m; i++){
    for (int j = 0; j < (1 << m); j++){
      if ((j >> i & 1) == 1){
        z[j - (1 << i)] += z[j];
      }
    }
  }
  int ans = m;
  for (int i = 0; i < (1 << m); i++){
    if (z[i] == 0){
      ans = min(ans, __builtin_popcount(i));
    }
  }
  cout << ans << endl;
}