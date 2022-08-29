#include <bits/stdc++.h>
using namespace std;
void dfs2(vector<vector<int>> &E, vector<bool> &used, vector<int> &dp, vector<int> &cc, int v, int p){
  dp[v] = 1;
  cc.push_back(v);
  for (int w : E[v]){
    if (!used[w] && w != p){
      dfs2(E, used, dp, cc, w, v);
      dp[v] += dp[w];
    }
  }
}
void dfs(vector<vector<int>> &E, vector<bool> &used, vector<int> &ans, vector<int> &dp, int r, int v){
  vector<int> cc;
  dfs2(E, used, dp, cc, v, -1);
  int N = cc.size();
  int c = -1;
  for (int i = 0; i < N; i++){
    int x = cc[i];
    if (N - dp[x] <= N / 2){
      bool ok = true;
      for (int w : E[x]){
        if (!used[w] && dp[w] < dp[x]){
          if (dp[w] > N / 2){
            ok = false;
          }
        }
      }
      if (ok){
        c = x;
      }
    }
  }
  ans[c] = r;
  used[c] = true;
  for (int w: E[c]){
    if (!used[w]){
      dfs(E, used, ans, dp, r + 1, w);
    }
  }
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<set<int>> p(n);
  for (int i = 0; i < n; i++){
    p[i].insert(0);
  }
  vector<set<int>> R(m + 1);
  for (int i = 0; i < n; i++){
    R[0].insert(i);
  }
  for (int i = 0; i < m; i++){
    //?
    if (p[a[i]].size() > p[b[i]].size()){
      swap(a[i], b[i]);
    }
    int r = -1;
    for (int x : p[a[i]]){
      if (R[x].count(b[i]) == 1){
        r = x;
      }
    }
    auto itr1 = R[r].lower_bound(a[i]);
    auto itr2 = R[r].lower_bound(b[i]);
    auto itr_n = itr2, itr_p = itr2;
    vector<int> A, B;
    while (true){
      itr_p++;
      if (itr_p == R[r].end()){
        itr_p = R[r].begin();
      }
      if (itr_n == R[r].begin()){
        itr_n = R[r].end();
      }
      itr_n--;
      if (itr_p == itr1){
        break;
      }
      if (itr_n == itr1){
        swap(A, B);
        break;
      }
      A.push_back(*itr_p);
      B.push_back(*itr_n);
    }
    for (int x : A){
      R[r].erase(x);
      p[x].erase(r);
      R[i + 1].insert(x);
      p[x].insert(i + 1);
    }
    R[i + 1].insert(a[i]);
    p[a[i]].insert(i + 1);
    R[i + 1].insert(b[i]);
    p[b[i]].insert(i + 1);
  }
  vector<vector<int>> R2(m + 1);
  for (int i = 0; i <= m; i++){
    for (int x : R[i]){
      R2[i].push_back(x);
    }
    reverse(R2[i].begin(), R2[i].end());
  }
  sort(R2.begin(), R2.end());
  map<pair<int, int>, int> mp;
  vector<vector<int>> E(m + 1);
  for (int i = 0; i <= m; i++){
    int cnt = R2[i].size();
    for (int j = 0; j < cnt; j++){
      int x = R2[i][j];
      int y;
      if (j < cnt - 1){
        y = R2[i][j + 1];
      } else {
        y = R2[i][0];
      }
      if (x > y){
        swap(x, y);
      }
      if (mp.count(make_pair(x, y)) == 1){
        int id = mp[make_pair(x, y)];
        E[i].push_back(id);
        E[id].push_back(i);
      } else {
        mp[make_pair(x, y)] = i;
      }
    }
  }
  vector<bool> used(m + 1, false);
  vector<int> ans(m + 1, -1);
  vector<int> dp(m + 1, -1);
  dfs(E, used, ans, dp, 0, 0);
  for (int i = 0; i <= m; i++){
    cout << ans[i] + 1;
    if (i < m){
      cout << ' ';
    }
  }
  cout << endl;
}