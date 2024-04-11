#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  vector<int> S(2000001, 0);
  vector<vector<int>> M(2000001);
  int c = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (i > 0){
      for (int j = a[i - 1] + 1; j <= a[i]; j++){
        for (int x : M[j]){
          S[j - x]--;
          int b = a[i] / x * x;
          S[b]++;
          M[b + x].push_back(x);
        }
      }
      while (S[c] == 0){
        c++;
      }
      ans = max(ans, a[i] - c);
    }
    S[a[i]]++;
    M[a[i] * 2].push_back(a[i]);
  }
  cout << ans << "\n";
}