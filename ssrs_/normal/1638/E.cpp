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
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<string> t(q);
  vector<int> A(q), B(q), C(q);
  for (int i = 0; i < q; i++){
    cin >> t[i];
    if (t[i] == "Color"){
      cin >> A[i] >> B[i] >> C[i];
      A[i]--;
    }
    if (t[i] == "Add"){
      cin >> A[i] >> B[i];
    }
    if (t[i] == "Query"){
      cin >> A[i];
      A[i]--;
    }
  }
  vector<int> color;
  for (int i = 0; i < q; i++){
    if (t[i] == "Color"){
      color.push_back(C[i]);
    }
    if (t[i] == "Add"){
      color.push_back(A[i]);
    }
  }
  color.push_back(1);
  sort(color.begin(), color.end());
  color.erase(unique(color.begin(), color.end()), color.end());
  int M = color.size();
  for (int i = 0; i < q; i++){
    if (t[i] == "Color"){
      C[i] = lower_bound(color.begin(), color.end(), C[i]) - color.begin();
    }
    if (t[i] == "Add"){
      A[i] = lower_bound(color.begin(), color.end(), A[i]) - color.begin();
    }
  }
  vector<vector<int>> query_add(n + 1), query_sub(n + 1);
  vector<vector<int>> query_get(n);
  for (int i = 0; i < q; i++){
    if (t[i] == "Color"){
      query_add[A[i]].push_back(i + 1);
      query_sub[B[i]].push_back(i + 1);
    }
    if (t[i] == "Query"){
      query_get[A[i]].push_back(i + 1);
    }
  }
  vector<vector<int>> pos(M);
  for (int i = 0; i < q; i++){
    if (t[i] == "Add"){
      pos[A[i]].push_back(i + 1);
    }
  }
  vector<vector<long long>> sum(M);
  for (int i = 0; i < M; i++){
    int cnt = pos[i].size();
    sum[i].resize(cnt + 1);
    sum[i][0] = 0;
    for (int j = 0; j < cnt; j++){
      sum[i][j + 1] = sum[i][j] + B[pos[i][j] - 1];
    }
  }
  set<tuple<int, int, int>> st;
  binary_indexed_tree<long long> BIT(q + 1);
  st.insert(make_tuple(0, q + 1, 0));
  BIT.add(0, sum[0].back());
  vector<long long> ans(q + 1);
  for (int i = 0; i < n; i++){
    for (int x : query_add[i]){
      auto itr = prev(st.lower_bound(make_tuple(x + 1, 0, 0)));
      int L = get<0>(*itr);
      int R = get<1>(*itr);
      int c = get<2>(*itr);
      int l1 = lower_bound(pos[c].begin(), pos[c].end(), x) - pos[c].begin();
      int r1 = lower_bound(pos[c].begin(), pos[c].end(), R) - pos[c].begin();
      BIT.add(L, -(sum[c][r1] - sum[c][l1]));
      int l2 = lower_bound(pos[C[x - 1]].begin(), pos[C[x - 1]].end(), x) - pos[C[x - 1]].begin();
      int r2 = lower_bound(pos[C[x - 1]].begin(), pos[C[x - 1]].end(), R) - pos[C[x - 1]].begin();
      BIT.add(x, sum[C[x - 1]][r2] - sum[C[x - 1]][l2]);
      st.erase(itr);
      st.insert(make_tuple(L, x, c));
      st.insert(make_tuple(x, R, C[x - 1]));
    }
    for (int x : query_sub[i]){
      auto itr = st.lower_bound(make_tuple(x, 0, 0));
      int L = get<0>(*prev(itr));
      int M = get<0>(*itr);
      int R = get<1>(*itr);
      int c = get<2>(*prev(itr));
      BIT.add(M, -BIT.sum(M, M + 1));
      int l1 = lower_bound(pos[c].begin(), pos[c].end(), M) - pos[c].begin();
      int r1 = lower_bound(pos[c].begin(), pos[c].end(), R) - pos[c].begin();
      BIT.add(L, sum[c][r1] - sum[c][l1]);
      st.erase(prev(itr));
      itr = st.lower_bound(make_tuple(x, 0, 0));
      st.erase(itr);
      st.insert(make_tuple(L, R, c));
    }
    for (int x : query_get[i]){
      auto itr = prev(st.lower_bound(make_tuple(x + 1, 0, 0)));
      int L = get<0>(*itr);
      int c = get<2>(*itr);
      ans[x] += BIT.sum(0, L);
      int l1 = lower_bound(pos[c].begin(), pos[c].end(), L) - pos[c].begin();
      int r1 = lower_bound(pos[c].begin(), pos[c].end(), x) - pos[c].begin();
      ans[x] += sum[c][r1] - sum[c][l1];
    }
  }
  for (int i = 0; i < q; i++){
    if (t[i] == "Query"){
      cout << ans[i + 1] << "\n";
    }
  }
}