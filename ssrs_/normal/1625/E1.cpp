#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> l, r;
  int cnt = 0;
  stack<int> st;
  for (int i = 0; i < n; i++){
    if (s[i] == '('){
      st.push(i);
    }
    if (s[i] == ')'){
      if (!st.empty()){
        l.push_back(st.top());
        r.push_back(i);
        cnt++;
        st.pop();
      }
    }
  }
  vector<int> id(n, -1);
  for (int i = 0; i < cnt; i++){
    id[l[i]] = i;
    id[r[i]] = i;
  }
  vector<int> pr(cnt + 1, -1);
  stack<int> st2;
  for (int i = 0; i < n; i++){
    if (s[i] == '(' && id[i] != -1){
      if (!st2.empty()){
        pr[id[i]] = st2.top();
      }
      st2.push(id[i]);
    }
    if (s[i] == ')' && id[i] != -1){
      st2.pop();
    }
  }
  for (int i = 0; i < cnt; i++){
    if (pr[i] == -1){
      pr[i] = cnt;
    }
  }
  vector<vector<int>> ch(cnt + 1);
  for (int i = 0; i < cnt; i++){
    ch[pr[i]].push_back(i);
  }
  vector<int> prv(cnt + 1, -1);
  for (int i = 0; i <= cnt; i++){
    int d = ch[i].size();
    for (int j = 0; j < d - 1; j++){
      prv[ch[i][j + 1]] = ch[i][j];
    }
  }
  vector<long long> dp(cnt + 1, 0);
  for (int i = 0; i <= cnt; i++){
    int x = ch[i].size();
    dp[i] = (long long) x * (x + 1) / 2;
    for (int j : ch[i]){
      dp[i] += dp[j];
    }
  }
  vector<long long> S1(cnt + 1, 0);
  for (int i = 0; i <= cnt; i++){
    S1[i] = dp[i];
    if (prv[i] != -1){
      S1[i] += S1[prv[i]];
    }
  }
  vector<int> S2(cnt + 1, 0);
  for (int i = 0; i <= cnt; i++){
    S2[i] = 1;
    if (prv[i] != -1){
      S2[i] += S2[prv[i]];
    }
  }
  for (int i = 0; i < q; i++){
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;
    l = id[l];
    r = id[r];
    long long ans1 = S1[r];
    int ans2 = S2[r];
    if (prv[l] != -1){
      ans1 -= S1[prv[l]];
      ans2 -= S2[prv[l]];
    }
    ans1 += (long long) ans2 * (ans2 + 1) / 2;
    cout << ans1 << "\n";
  }
}