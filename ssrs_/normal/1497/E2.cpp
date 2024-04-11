#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
const int INF = 1000000;
int main(){
  vector<int> s(MAX + 1);
  for (int i = 0; i <= MAX; i++){
    s[i] = i;
  }
  for (int i = 2; i * i <= MAX; i++){
    for (int j = i * i; j <= MAX; j += i * i){
      while (s[j] % (i * i) == 0){
        s[j] /= i * i;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j] = s[a[j]];
    }
    map<int, int> mp;
    set<int> st;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++){
      if (mp.count(a[j])){
        st.insert(mp[a[j]]);
      }
      mp[a[j]] = j;
      vector<int> p;
      for (auto itr = st.rbegin(); itr != st.rend(); itr++){
        if (p.size() > k){
          break;
        }
        p.push_back(*itr);
      }
      int cnt = p.size();
      p.push_back(-1);
      sort(p.begin(), p.end());
      for (int l = 0; l <= k; l++){
        for (int m = 0; m <= cnt; m++){
          if (l + m <= k){
            dp[l + m][j + 1] = min(dp[l + m][j + 1], dp[l][p[cnt - m] + 1] + 1);
          }
        }
      }
    }
    int ans = INF;
    for (int j = 0; j <= k; j++){
      ans = min(ans, dp[j][n]);
    }
    cout << ans << endl;
  }
}