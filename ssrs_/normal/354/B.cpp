#include <bits/stdc++.h>
using namespace std;
int dfs(vector<map<pair<int, int>, int>> &dp, vector<string> &T, vector<vector<pair<int, int>>> &D, vector<vector<int>> &id, int d, int s, int c){
  int N = T.size();
  if (d == N * 2 - 2){
    if (c > 0){
      return 1;
    }
    if (c < 0){
      return -1;
    }
    if (c == 0){
      return 0;
    }
  } else {
    if (dp[d].count(make_pair(s, c)) == 1){
      return dp[d][make_pair(s, c)];
    }
    vector<int> nxt(26, 0);
    int cnt = D[d].size();
    for (int i = 0; i < cnt; i++){
      if ((s >> i & 1) == 1){
        int x = D[d][i].first;
        int y = D[d][i].second;
        if (x < N - 1){
          int ch = T[x + 1][y] - 'a';
          nxt[ch] |= 1 << id[x + 1][y];
        }
        if (y < N - 1){
          int ch = T[x][y + 1] - 'a';
          nxt[ch] |= 1 << id[x][y + 1];
        }
      }
    }
    vector<int> p;
    for (int i = 0; i < 26; i++){
      if (nxt[i] != 0){
        if (i == 0){
          p.push_back(dfs(dp, T, D, id, d + 1, nxt[i], c + 1));
        } else if (i == 1){
          p.push_back(dfs(dp, T, D, id, d + 1, nxt[i], c - 1));
        } else {
          p.push_back(dfs(dp, T, D, id, d + 1, nxt[i], c));
        }
      }
    }
    sort(p.begin(), p.end());
    int ans;
    if (d % 2 == 1){
      ans = p.back();
    } else {
      ans = p.front();
    }
    dp[d][make_pair(s, c)] = ans;
    return ans;
  }
}
int main(){
  int n;
  cin >> n;
  vector<string> T(n);
  for (int i = 0; i < n; i++){
    cin >> T[i];
  }
  vector<vector<pair<int, int>>> D(n * 2 - 1);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      D[i + j].push_back(make_pair(i, j));
    }
  }
  vector<int> cnt(n * 2 - 1);
  for (int i = 0; i < n * 2 - 1; i++){
    cnt[i] = D[i].size();
  }
  vector<vector<int>> id(n, vector<int>(n));
  for (int i = 0; i < n * 2 - 1; i++){
    for (int j = 0; j < cnt[i]; j++){
      int x = D[i][j].first;
      int y = D[i][j].second;
      id[x][y] = j;
    }
  }
  vector<map<pair<int, int>, int>> dp(n * 2 - 1);
  int ans;
  if (T[0][0] == 'a'){
    ans = dfs(dp, T, D, id, 0, 1, 1);
  } else if (T[0][0] == 'b'){
    ans = dfs(dp, T, D, id, 0, 1, -1);
  } else {
    ans = dfs(dp, T, D, id, 0, 1, 0);
  }
  if (ans == 1){
    cout << "FIRST" << endl;
  }
  if (ans == -1){
    cout << "SECOND" << endl;
  }
  if (ans == 0){
    cout << "DRAW" << endl;
  }
}