#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &c, vector<int> &a, vector<int> &b, vector<int> &r, vector<long long> &S, long long s, int v = 0){
  if (v != 0){
    r[v] = upper_bound(S.begin(), S.end(), s) - S.begin() - 1;
  }
  long long sum = S.back();
  for (int w : c[v]){
    S.push_back(sum + b[w]);
    dfs(c, a, b, r, S, s + a[w], w);
    S.pop_back();
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    for (int j = 1; j < n; j++){
      cin >> p[j] >> a[j] >> b[j];
      p[j]--;
    }
    vector<vector<int>> c(n);
    for (int j = 1; j < n; j++){
      c[p[j]].push_back(j);
    }
    vector<int> r(n);
    vector<long long> S = {0};
    dfs(c, a, b, r, S, 0);
    for (int j = 1; j < n; j++){
      cout << r[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}