#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int x = 0, y = n;
    int R = 0;
    int sum = 0;
    for (int L = 0; L < n; L++){
      while (R < n && sum - (n - sum) < k){
        sum += cnt[R];
        R++;
      }
      if (sum - (n - sum) >= k){
        if (y - x > R - L){
          x = L;
          y = R;
        }
      }
      sum -= cnt[L];
    }
    vector<int> S(n + 1, 0);
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j];
      if (x <= a[j] && a[j] < y){
        S[j + 1]++;
      } else {
        S[j + 1]--;
      }
    }
    vector<int> p(k + 1, -1);
    for (int j = 0; j <= n; j++){
      if (0 <= S[j] && S[j] <= k){
        if (p[S[j]] == -1){
          p[S[j]] = j;
        }
      }
    }
    p[k] = n;
    cout << x + 1 << ' ' << y << "\n";
    for (int j = 0; j < k; j++){
      cout << p[j] + 1 << ' ' << p[j + 1] << "\n";
    }
  }
}