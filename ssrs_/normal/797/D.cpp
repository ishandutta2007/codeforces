#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int dfs(map<int, int> &mp, vector<int> &a, vector<int> &l, vector<int> &r, int v, int mn, int mx){
  int ans = 0;
  if (mn <= a[v] && a[v] <= mx){
    ans += mp[a[v]];
  }
  if (l[v] != -1){
    ans += dfs(mp, a, l, r, l[v], mn, min(mx, a[v] - 1));
  }
  if (r[v] != -1){
    ans += dfs(mp, a, l, r, r[v], max(mn, a[v] + 1), mx);
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n), l(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> l[i] >> r[i];
    if (l[i] != -1){
      l[i]--;
    }
    if (r[i] != -1){
      r[i]--;
    }
  }
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++){
    if (l[i] != -1){
      used[l[i]] = true;
    }
    if (r[i] != -1){
      used[r[i]] = true;
    }
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]]++;
  }
  int root;
  for (int i = 0; i < n; i++){
    if (!used[i]){
      root = i;
    }
  }
  cout << n - dfs(mp, a, l, r, root, 0, INF) << endl;
}