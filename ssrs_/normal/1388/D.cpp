#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<long long> &a, vector<vector<int>> &c, vector<vector<int>> &pre, vector<vector<int>> &post, int v){
  for (int w : c[v]){
    dfs1(a, c, pre, post, w);
    if (a[w] > 0){
      pre[v].push_back(w);
      a[v] += a[w];
    } else {
      post[v].push_back(w);
    }
  }
  return;
}
void dfs2(vector<int> &p, vector<vector<int>> &pre, vector<vector<int>> &post, int v){
  for (int w : pre[v]){
    dfs2(p, pre, post, w);
  }
  p.push_back(v);
  for (int w : post[v]){
    dfs2(p, pre, post, w);
  }
  return;
}
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
    b[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 0; i < n; i++){
    if (b[i] != -2){
      c[b[i]].push_back(i);
    }
  }
  vector<vector<int>> pre(n);
  vector<vector<int>> post(n);
  for (int i = 0; i < n; i++){
    if (b[i] == -2){
      dfs1(a, c, pre, post, i);
    }
  }
  vector<int> p;
  for (int i = 0; i < n; i++){
    if (b[i] == -2){
      dfs2(p, pre, post, i);
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++){
    cout << p[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}