#include <bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int, int>> &P, int L, int R, int x, int p, int l, int r){
  if (r <= L || R <= l){
    return;
  } else if (L <= l && r <= R){
    x ^= x & ((1 << p) - 1);
    P.push_back(make_pair(l ^ x, (l ^ x) + (1 << p)));
  } else {
    int m = (l + r) / 2;
    dfs(P, L, R, x, p - 1, l, m);
    dfs(P, L, R, x, p - 1, m, r);
  }
}
vector<pair<int, int>> xor_ranges(int L, int R, int x){
  vector<pair<int, int>> P;
  dfs(P, L, R, x, 30, 0, 1 << 30);
  sort(P.begin(), P.end());
  int cnt = P.size();
  vector<pair<int, int>> ans;
  ans.push_back(P[0]);
  for (int i = 1; i < cnt; i++){
    if (ans.back().second == P[i].first){
      ans.back().second = P[i].second;
    } else {
      ans.push_back(P[i]);
    }
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> P = xor_ranges(0, m + 1, n);
    int cnt = P.size();
    if (P[0].first != 0){
      cout << 0 << endl;
    } else {
      cout << P[0].second << endl;
    }
  }
}