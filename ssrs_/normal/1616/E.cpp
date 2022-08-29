#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
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
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<queue<int>> Q(26);
    for (int j = 0; j < n; j++){
      Q[s[j] - 'a'].push(j);
    }
    binary_indexed_tree<int> BIT(n);
    for (int j = 0; j < n; j++){
      BIT.add(j, 1);
    }
    long long ans = INF;
    long long cnt = 0;
    for (int j = 0; j < n; j++){
      int p = t[j] - 'a';
      int mn = n;
      for (int k = 0; k < p; k++){
        if (!Q[k].empty()){
          mn = min(mn, Q[k].front());
        }
      }
      if (mn != n){
        ans = min(ans, cnt + BIT.sum(mn));
      }
      if (Q[p].empty()){
        break;
      }
      int x = Q[p].front();
      Q[p].pop();
      cnt += BIT.sum(x);
      BIT.add(x, -1);
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}