#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + v[i];
  }
  vector<long long> T(n);
  for (int i = 1; i <= n; i++){
    T[i - 1] = (S[i] + i - 1)/ i;
  }
  vector<long long> L(n + 1);
  L[0] = 0;
  for (int i = 0; i < n; i++){
    L[i + 1] = max(L[i], T[i]);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t < L[n]){
      cout << -1 << "\n";
    } else {
      int tv = n, fv = 0;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        if (L[mid] <= t && (long long) mid * t >= S[n]){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      cout << tv << "\n";
    }
  }
}