#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> b;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(b.begin(), b.end());
  vector<pair<int, int>> dp1(n);
  for (int v : b){
    dp1[v] = make_pair(0, v);
    for (int w : c[v]){
      dp1[v] = max(dp1[v], make_pair(dp1[w].first + 1, dp1[w].second));
    }
  }
  reverse(b.begin(), b.end());
  vector<pair<int, int>> dp2(n);
  dp2[0] = make_pair(0, 0);
  for (int v : b){
    int cnt = c[v].size();
    vector<pair<int, int>> L(cnt + 1, make_pair(-1, -1));
    for (int i = 0; i < cnt; i++){
      L[i + 1] = max(L[i], dp1[c[v][i]]);
    }
    vector<pair<int, int>> R(cnt + 1, make_pair(-1, -1));
    for (int i = cnt - 1; i >= 0; i--){
      R[i] = max(R[i + 1], dp1[c[v][i]]);
    }
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      dp2[w] = max(dp2[w], make_pair(dp2[v].first + 1, dp2[v].second));
      dp2[w] = max(dp2[w], make_pair(L[i].first + 2, L[i].second));
      dp2[w] = max(dp2[w], make_pair(R[i + 1].first + 2, R[i + 1].second));
    }
  }
  int ans = 0;
  int A, B, C;
  for (int v : b){
    vector<pair<int, int>> num;
    num.push_back(make_pair(0, v));
    if (v != 0){
      num.push_back(dp2[v]);
    }
    for (int w : c[v]){
      num.push_back(make_pair(dp1[w].first + 1, dp1[w].second));
    }
    if (num.size() >= 3){
      sort(num.begin(), num.end(), greater<pair<int, int>>());
      int sum = num[0].first + num[1].first + num[2].first;
      if (sum > ans){
        ans = sum;
        A = num[0].second;
        B = num[1].second;
        C = num[2].second;
      }
    }
  }
  cout << ans << endl;
  cout << A + 1 << ' ' << B + 1 << ' ' << C + 1 << endl;
}