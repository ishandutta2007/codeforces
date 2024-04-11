#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> u(n);
    for (int j = 0; j < n; j++){
      cin >> u[j];
      u[j]--;
    }
    vector<int> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<vector<int>> a(n);
    for (int j = 0; j < n; j++){
      a[u[j]].push_back(s[j]);
    }
    vector<long long> ans(n + 1, 0);
    for (int j = 0; j < n; j++){
      sort(a[j].begin(), a[j].end(), greater<int>());
      int cnt = a[j].size();
      vector<long long> S(cnt + 1);
      S[0] = 0;
      for (int k = 0; k < cnt; k++){
        S[k + 1] = S[k] + a[j][k];
      }
      for (int k = 1; k <= cnt; k++){
        ans[k] += S[cnt / k * k];
      }
    }
    for (int j = 1; j <= n; j++){
      cout << ans[j];
      if (j < n){
        cout << ' ';
      }
    }
    cout << endl;
  }
}