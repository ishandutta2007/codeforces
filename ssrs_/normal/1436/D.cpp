#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &c, vector<long long> &a, int v = 0){
  for (int w : c[v]){
    dfs(c, a, w);
    a[v] += a[w];
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> p(n, -1);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> b(n, 1);
  for (int i = 1; i < n; i++){
    b[p[i]] = 0;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  dfs(c, a);
  dfs(c, b);
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans = max(ans, (a[i] + b[i] - 1) / b[i]);
  }
  cout << ans << endl;
}