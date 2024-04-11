#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &state, vector<vector<vector<int>>> &pos, vector<int> &p, int id, int c){
  if (c == pos.size()){
    state.push_back(p);
  } else {
    for (int j : pos[c][id]){
      p[c] = j;
      dfs(state, pos, p, id, c + 1);
    }
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<vector<vector<int>>> pos(n - 1, vector<vector<int>>(52));
    for (int j = 0; j < n - 1; j++){
      int L = s[j].size();
      for (int k = 0; k < L; k++){
        int id;
        if (isupper(s[j][k]) != 0){
          pos[j][s[j][k] - 'A'].push_back(k);
        } else {
          pos[j][s[j][k] - 'a' + 26].push_back(k);
        }
      }
    }
    vector<vector<int>> state;
    for (int j = 0; j < 52; j++){
      vector<int> p(n - 1);
      dfs(state, pos, p, j, 0);
    }
    sort(state.begin(), state.end());
    int V = state.size();
    vector<int> letter(V);
    for (int j = 0; j < V; j++){
      char c = s[0][state[j][0]];
      if (isupper(c) != 0){
        letter[j] = c - 'A';
      } else {
        letter[j] = c - 'a' + 26;
      }
    }
    vector<vector<int>> id(52);
    for (int j = 0; j < V; j++){
      id[letter[j]].push_back(j);
    }
    int L = s[n - 1].size();
    vector<vector<int>> dp(L + 1, vector<int>(V, 0));
    vector<vector<int>> pr(L + 1, vector<int>(V));
    for (int j = 0; j < L; j++){
      char c = s[n - 1][j];
      int id2;
      if (isupper(c) != 0){
        id2 = c - 'A';
      } else {
        id2 = c - 'a' + 26;
      }
      for (int k = 0; k < V; k++){
        dp[j + 1][k] = dp[j][k];
        pr[j + 1][k] = k;
      }
      for (int k : id[id2]){
        if (dp[j + 1][k] == 0){
          dp[j + 1][k] = 1;
        }
      }
      for (int k = 0; k < V; k++){
        vector<int> nxt(n - 1);
        bool ok = true;
        for (int l = 0; l < n - 1; l++){
          auto itr = upper_bound(pos[l][id2].begin(), pos[l][id2].end(), state[k][l]);
          if (itr == pos[l][id2].end()){
            ok = false;
            break;
          } else {
            nxt[l] = *itr;
          }
        }
        if (ok){
          int nxt_id = lower_bound(state.begin(), state.end(), nxt) - state.begin();
          if (dp[j + 1][nxt_id] < dp[j][k] + 1){
            dp[j + 1][nxt_id] = dp[j][k] + 1;
            pr[j + 1][nxt_id] = k;
          }
        }
      }
    }
    int ans = 0;
    int curr = 0;
    for (int j = 0; j < V; j++){
      if (ans < dp[L][j]){
        ans = dp[L][j];
        curr = j;
      }
    }
    cout << ans << endl;
    string lcs;
    for (int j = L; j >= 1; j--){
      int p = pr[j][curr];
      if (dp[j - 1][p] < dp[j][curr]){
        lcs += s[n - 1][j - 1];
      }
      if (dp[j - 1][p] == 0){
        break;
      }
      curr = p;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
  }
}