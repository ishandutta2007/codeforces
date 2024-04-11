#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> u(m), v(m);
  for (int i = 0; i < m; i++){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  vector<tuple<long long, long long, long long, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_tuple(x[i] - y[i], x[i], y[i], i);
  }
  sort(P.begin(), P.end());
  vector<long long> L(n + 1, 0);
  for (int i = 0; i < n; i++){
    L[i + 1] = L[i] + get<1>(P[i]);
  }
  vector<long long> R(n + 1, 0);
  for (int i = n - 1; i >= 0; i--){
    R[i] = R[i + 1] + get<2>(P[i]);
  }
  vector<long long> ans(n, 0);
  for (int i = 0; i < n; i++){
    int id = get<3>(P[i]);
    ans[id] += get<1>(P[i]) * (n - i - 1);
    ans[id] += get<2>(P[i]) * i;
    ans[id] += L[i];
    ans[id] += R[i + 1];
  }
  for (int i = 0; i < m; i++){
    int s = min(x[u[i]] + y[v[i]], x[v[i]] + y[u[i]]);
    ans[u[i]] -= s;
    ans[v[i]] -= s;
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}