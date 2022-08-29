#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &c, vector<int> &L, vector<int> &R, int &t, int v){
  L[v] = t;
  t++;
  for (int w : c[v]){
    dfs(c, L, R, t, w);
  }
  R[v] = t;
}
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(vector<T> A){
    N = A.size();
    BIT = vector<T>(N + 1, 0);
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i <= N; i++){
      if (i + (i & -i) <= N){
        BIT[i + (i & -i)] += BIT[i];
      }
    }
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
  string s;
  cin >> s;
  vector<int> l, r;
  int cnt = 0;
  stack<int> st;
  for (int i = 0; i < n; i++){
    if (s[i] == '('){
      st.push(i);
    }
    if (s[i] == ')'){
      if (!st.empty()){
        l.push_back(st.top());
        r.push_back(i);
        cnt++;
        st.pop();
      }
    }
  }
  vector<int> id(n, -1);
  for (int i = 0; i < cnt; i++){
    id[l[i]] = i;
    id[r[i]] = i;
  }
  vector<int> pr(cnt + 1, -1);
  stack<int> st2;
  for (int i = 0; i < n; i++){
    if (s[i] == '(' && id[i] != -1){
      if (!st2.empty()){
        pr[id[i]] = st2.top();
      }
      st2.push(id[i]);
    }
    if (s[i] == ')' && id[i] != -1){
      st2.pop();
    }
  }
  for (int i = 0; i < cnt; i++){
    if (pr[i] == -1){
      pr[i] = cnt;
    }
  }
  vector<vector<int>> ch(cnt + 1);
  for (int i = 0; i < cnt; i++){
    ch[pr[i]].push_back(i);
  }
  vector<int> left(cnt + 1, -1);
  for (int i = 0; i <= cnt; i++){
    int d = ch[i].size();
    for (int j = 0; j < d; j++){
      left[ch[i][j]] = ch[i][0];
    }
  }
  left[cnt] = cnt;
  vector<int> d(cnt + 1, 0);
  for (int i = 0; i <= cnt; i++){
    d[i] = ch[i].size();
  }
  vector<long long> A(cnt + 1, 0);
  for (int i = 0; i <= cnt; i++){
    A[i] = (long long) d[i] * (d[i] + 1) / 2;
  }
  vector<int> L(cnt + 1), R(cnt + 1);
  int T = 0;
  dfs(ch, L, R, T, cnt);
  vector<long long> B(cnt + 1, 0);
  for (int i = 0; i <= cnt; i++){
    B[L[i]] = A[i];
  }
  binary_indexed_tree<long long> BIT1(B);
  vector<vector<int>> id_left(cnt + 1);
  for (int i = 0; i <= cnt; i++){
    id_left[left[i]].push_back(i);
  }
  vector<int> P;
  for (int i = 0; i <= cnt; i++){
    for (int j : id_left[i]){
      P.push_back(j);
    }
  }
  vector<int> pos(cnt + 1);
  for (int i = 0; i <= cnt; i++){
    pos[P[i]] = i;
  }
  binary_indexed_tree<int> BIT2(vector<int>(cnt + 1, 1));
  for (int i = 0; i < q; i++){
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;
    l = id[l];
    r = id[r];
    if (t == 1){
      int p = pr[l];
      d[p]--;
      long long A2 = (long long) d[p] * (d[p] + 1) / 2;
      BIT1.add(L[p], A2 - A[p]);
      A[p] = A2;
      BIT2.add(pos[l], -1);
    }
    if (t == 2){
      long long ans1 = BIT1.sum(L[l], R[r]);
      int ans2 = BIT2.sum(pos[l], pos[r] + 1);
      cout << ans1 + (long long) ans2 * (ans2 + 1) / 2 << "\n";
    }
  }
}