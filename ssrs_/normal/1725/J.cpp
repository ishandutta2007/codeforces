#include <bits/stdc++.h>
using namespace std;
long long top2(long long a, long long b, long long c){
  return a + b + c - min({a, b, c});
}
long long top4(long long a,  long long b, long long c, long long d, long long e){
  return a + b + c + d + e - min({a, b, c, d, e});
}
long long solve1(vector<int> &p, vector<int> &a, vector<vector<int>> &c, vector<int> &bfs){
  reverse(bfs.begin(), bfs.end());
  int N = p.size();
  vector<long long> dp1(N, 0), dp2(N, 0), dp3(N, 0);
  vector<int> mx1(N, -1), mx2(N, -1);
  for (int v : bfs){
    vector<pair<long long, int>> A;
    for (int w : c[v]){
      A.push_back(make_pair(dp1[w] + a[w], w));
    }
    sort(A.begin(), A.end(), greater<pair<long long, int>>());
    if (A.size() >= 1){
      dp1[v] = A[0].first;
      mx1[v] = A[0].second;
    }
    if (A.size() >= 2){
      dp2[v] = A[1].first;
      mx2[v] = A[1].second;
    }
    if (A.size() >= 3){
      dp3[v] = A[2].first;
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<long long> dp4(N, 0);
  for (int v : bfs){
    int cnt = c[v].size();
    vector<long long> L(cnt + 1, 0);
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      L[i + 1] = max(L[i], dp1[w] + a[w]);
    }
    vector<long long> R(cnt + 1, 0);
    for (int i = cnt - 1; i >= 0; i--){
      int w = c[v][i];
      R[i] = max(R[i + 1], dp1[w] + a[w]);
    }
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      dp4[w] = max({L[i], R[i + 1], dp4[v]}) + a[w];
    }
  }
  long long ans = 0;
  for (int i = 1; i < N; i++){
    long long sum = dp1[i] + dp2[i] + a[i] * 2;
    if (i == mx1[p[i]]){
      sum += top2(dp2[p[i]], dp3[p[i]], dp4[p[i]]);
    } else if (i == mx2[p[i]]){
      sum += top2(dp1[p[i]], dp3[p[i]], dp4[p[i]]);
    } else {
      sum += top2(dp1[p[i]], dp2[p[i]], dp4[p[i]]);
    }
    ans = max(ans, sum);
  }
  return ans;
}
long long solve2(vector<int> &p, vector<int> &a, vector<vector<int>> &c, vector<int> &bfs){
  reverse(bfs.begin(), bfs.end());
  int N = p.size();
  vector<vector<long long>> dp1(4, vector<long long>(N, 0));
  for (int v : bfs){
    vector<long long> A;
    for (int w : c[v]){
      A.push_back(dp1[0][w] + a[w]);
    }
    sort(A.begin(), A.end(), greater<long long>());
    for (int i = 0; i < 4; i++){
      if (A.size() > i){
        dp1[i][v] = A[i];
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<long long> dp2(N, 0);
  for (int v : bfs){
    int cnt = c[v].size();
    vector<long long> L(cnt + 1, 0);
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      L[i + 1] = max(L[i], dp1[0][w] + a[w]);
    }
    vector<long long> R(cnt + 1, 0);
    for (int i = cnt - 1; i >= 0; i--){
      int w = c[v][i];
      R[i] = max(R[i + 1], dp1[0][w] + a[w]);
    }
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      dp2[w] = max({L[i], R[i + 1], dp2[v]}) + a[w];
    }
  }
  long long ans = 0;
  ans = max(ans, dp1[0][0] + dp1[1][0] + dp1[2][0] + dp1[3][0]);
  for (int i = 1; i < N; i++){
    ans = max(ans, top4(dp1[0][i], dp1[1][i], dp1[2][i], dp1[3][i], dp2[i]));
  }
  return ans;
}
long long solve3(vector<int> &p, vector<int> &a, vector<vector<int>> &c, vector<int> &bfs){
  reverse(bfs.begin(), bfs.end());
  int N = p.size();
  vector<long long> dp1(N, 0);
  vector<long long> d1(N, 0);
  for (int v : bfs){
    vector<long long> A;
    for (int w : c[v]){
      dp1[v] = max(dp1[v], dp1[w] + a[w]);
      d1[v] = max(d1[v], d1[w]);
      A.push_back(dp1[w] + a[w]);
    }
    sort(A.begin(), A.end(), greater<long long>());
    if (A.size() >= 1){
      d1[v] = max(d1[v], A[0]);
    }
    if (A.size() >= 2){
      d1[v] = max(d1[v], A[0] + A[1]);
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<long long> dp2(N, 0);
  vector<long long> d2(N, 0);
  for (int v : bfs){
    int cnt = c[v].size();
    vector<long long> L1(cnt + 1, 0), L2(cnt + 1, 0), L(cnt + 1, 0);
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      L1[i + 1] = max(L1[i], dp1[w] + a[w]);
      L2[i + 1] = max(L2[i], min(L1[i], dp1[w] + a[w]));
      L[i + 1] = max(L[i], d1[w]);
    }
    vector<long long> R1(cnt + 1, 0), R2(cnt + 1, 0), R(cnt + 1, 0);
    for (int i = cnt - 1; i >= 0; i--){
      int w = c[v][i];
      R1[i] = max(R1[i + 1], dp1[w] + a[w]);
      R2[i] = max(R2[i + 1], min(R1[i + 1], dp1[w] + a[w]));
      R[i] = max(R[i + 1], d1[w]);
    }
    for (int i = 0; i < cnt; i++){
      int w = c[v][i];
      dp2[w] = max(L1[i] + a[w], R1[i + 1] + a[w]);
      dp2[w] = max(dp2[w], dp2[v] + a[w]);
      d2[w] = max(L[i], R[i + 1]);
      d2[w] = max(d2[w], L1[i] + L2[i]);
      d2[w] = max(d2[w], R1[i + 1] + R2[i + 1]);
      d2[w] = max(d2[w], L1[i] + R1[i + 1]);
      d2[w] = max(d2[w], d2[v]);
      d2[w] = max(d2[w], dp2[v] + L1[i]);
      d2[w] = max(d2[w], dp2[v] + R1[i + 1]);
    }
  }
  long long ans = 0;
  for (int i = 1; i < N; i++){
    ans = max(ans, d1[i] + d2[i] + a[i] * 2);
  }
  return ans;
}
int main(){
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> E(N);
  long long sum = 0;
  for (int i = 0; i < N - 1; i++){
    int U, V, W;
    cin >> U >> V >> W;
    U--;
    V--;
    E[U].push_back(make_pair(W, V));
    E[V].push_back(make_pair(W, U));
    sum += W * 2;
  }
  vector<int> p(N, -1);
  vector<int> a(N);
  vector<vector<int>> c(N);
  queue<int> Q;
  vector<int> bfs;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (auto e : E[v]){
      int w = e.second;
      if (w != p[v]){
        p[w] = v;
        a[w] = e.first;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  long long ans1 = solve1(p, a, c, bfs);
  long long ans2 = solve2(p, a, c, bfs);
  long long ans3 = solve3(p, a, c, bfs);
  long long ans = max({ans1, ans2, ans3});
  cout << sum - ans << endl;
}