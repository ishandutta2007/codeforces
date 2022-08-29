#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
void dfs(int n, vector<vector<int>> &c, vector<int> &a, vector<int> &ans, vector<vector<tuple<int, int, int>>> &query, vector<int> &freq, binary_indexed_tree<int> &freq_cnt, vector<set<int>> &st, int v = 0){
  freq_cnt.add(freq[a[v]], -1);
  st[freq[a[v]]].erase(a[v]);
  freq[a[v]]++;
  freq_cnt.add(freq[a[v]], 1);
  st[freq[a[v]]].insert(a[v]);
  for (auto &q : query[v]){
    int l = get<0>(q);
    int k = get<1>(q);
    int id = get<2>(q);
    if (freq_cnt.sum(l, n + 1) < k){
      ans[id] = -2;
    } else {
      int tv = n + 1, fv = l;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        if (freq_cnt.sum(l, mid) >= k){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      ans[id] = *st[fv].begin();
    }
  }
  for (int w : c[v]){
    dfs(n, c, a, ans, query, freq, freq_cnt, st, w);
  }
  freq_cnt.add(freq[a[v]], -1);
  st[freq[a[v]]].erase(a[v]);
  freq[a[v]]--;
  freq_cnt.add(freq[a[v]], 1);
  st[freq[a[v]]].insert(a[v]);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> p(n, -1);
    for (int j = 1; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<vector<tuple<int, int, int>>> query(n);
    for (int j = 0; j < q; j++){
      int v, l, k;
      cin >> v >> l >> k;
      v--;
      query[v].push_back(make_tuple(l, k, j));
    }
    vector<vector<int>> c(n);
    for (int j = 1; j < n; j++){
      c[p[j]].push_back(j);
    }
    vector<int> freq(n, 0);
    binary_indexed_tree<int> freq_cnt(n + 1);
    freq_cnt.add(0, n);
    vector<set<int>> st(n + 1);
    for (int i = 0; i < n; i++){
      st[0].insert(i);
    }
    vector<int> ans(q);
    dfs(n, c, a, ans, query, freq, freq_cnt, st);
    for (int j = 0; j < q; j++){
      cout << ans[j] + 1;
      if (j < q - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}