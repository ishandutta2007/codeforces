#include <bits/stdc++.h>
using namespace std;
vector<double> merge(vector<double> A, vector<double> B){
  int N = A.size();
  vector<double> SA(N + 1);
  SA[0] = 0;
  for (int i = 0; i < N; i++){
    SA[i + 1] = SA[i] + A[i];
  }
  vector<double> SB(N + 1);
  SB[0] = 0;
  for (int i = 0; i < N; i++){
    SB[i + 1] = SB[i] + B[i];
  }
  vector<double> SC(N + 1);
  for (int i = 0; i <= N; i++){
    SC[i] = SA[i] * SB[i];
  }
  vector<double> C(N);
  for (int i = 0; i < N; i++){
    C[i] = SC[i + 1] - SC[i];
  }
  return C;
}
int main(){
  cout << fixed << setprecision(20);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> l(q + 1), r(q + 1);
  vector<double> p(q + 1);
  for (int i = 0; i < q; i++){
    cin >> l[i] >> r[i] >> p[i];
    l[i]--;
  }
  l[q] = 0;
  r[q] = n;
  p[q] = 0;
  q++;
  vector<int> pr(q, -1);
  vector<vector<int>> ch(q);
  for (int i = 0; i < q - 1; i++){
    for (int j = 0; j < q; j++){
      if (i != j){
        if (l[j] <= l[i] && r[i] <= r[j]){
          if (l[i] == l[j] && r[i] == r[j] && j < i){
            continue;
          }
          if (pr[i] == -1){
            pr[i] = j;
          } else if (r[j] - l[j] < r[pr[i]] - l[pr[i]]){
            pr[i] = j;
          }
        }
      }
    }
    ch[pr[i]].push_back(i);
  }
  vector<int> mx(q, 0);
  for (int i = 0; i < q; i++){
    vector<int> cl, cr;
    for (int j : ch[i]){
      cl.push_back(l[j]);
      cr.push_back(r[j]);
    }
    sort(cl.begin(), cl.end());
    sort(cr.begin(), cr.end());
    int cnt = ch[i].size();
    vector<int> L, R;
    L.push_back(l[i]);
    for (int j = 0; j < cnt; j++){
      R.push_back(cl[j]);
      L.push_back(cr[j]);
    }
    R.push_back(r[i]);
    for (int j = 0; j <= cnt; j++){
      for (int k = L[j]; k < R[j]; k++){
        mx[i] = max(mx[i], a[k]);
      }
    }
  }
  int m = 0;
  for (int i = 0; i < q; i++){
    m = max(m, mx[i]);
  }
  int add = m - q + 1;
  for (int i = 0; i < q; i++){
    mx[i] = max(mx[i] - add, 0);
  }
  vector<int> b;
  queue<int> Q;
  Q.push(q - 1);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int w : ch[v]){
      Q.push(w);
    }
  }
  reverse(b.begin(), b.end());
  vector<vector<double>> dp(q, vector<double>(q * 2, 0));
  for (int v : b){
    vector<double> dp2(q * 2, 0);
    dp2[mx[v]] = 1;
    for (int w : ch[v]){
      dp2 = merge(dp2, dp[w]);
    }
    for (int i = 0; i < q * 2 - 1; i++){
      dp[v][i + 1] += dp2[i] * p[v];
      dp[v][i] += dp2[i] * (1 - p[v]);
    }
  }
  double ans = 0;
  for (int i = 0; i < q * 2 - 1; i++){
    ans += dp[q - 1][i] * i;
  }
  ans += add;
  cout << ans << endl;
}