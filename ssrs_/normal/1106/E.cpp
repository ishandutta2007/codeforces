#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> s(k), t(k), d(k), w(k);
  for (int i = 0; i < k; i++){
    cin >> s[i] >> t[i] >> d[i] >> w[i];
    s[i]--;
  }
  vector<tuple<int, int, int>> T(k);
  for (int i = 0; i < k; i++){
    T[i] = make_tuple(w[i], d[i], i);
  }
  sort(T.begin(), T.end(), greater<tuple<int, int, int>>());
  vector<int> p(k);
  for (int i = 0; i < k; i++){
    p[get<2>(T[i])] = i;
  }
  vector<vector<int>> add(n + 1), sub(n + 1);
  for (int i = 0; i < k; i++){
    add[s[i]].push_back(p[i]);
    sub[t[i]].push_back(p[i]);
  }
  set<int> st;
  vector<int> W(n), D(n);
  for (int i = 0; i < n; i++){
    for (int j : add[i]){
      st.insert(j);
    }
    for (int j : sub[i]){
      st.erase(j);
    }
    if (!st.empty()){
      int id = *st.begin();
      W[i] = get<0>(T[id]);
      D[i] = get<1>(T[id]);
    } else {
      W[i] = 0;
      D[i] = i + 1;
    }
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
    }
    for (int j = 0; j <= m; j++){
      dp[D[i]][j] = min(dp[D[i]][j], dp[i][j] + W[i]);
    }
  }
  long long ans = INF;
  for (int i = 0; i <= m; i++){
    ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;
}