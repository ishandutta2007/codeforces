#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  vector<long long> sum;
  unionfind(vector<long long> a){
    int N = a.size();
    p = vector<int>(N, -1);
    sum = a;
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  long long unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      p[x] = y;
      sum[y] += sum[x];
    }
    return sum[y];
  }
};
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<bool> in(n, false);
  vector<long long> ans(n);
  long long mx = 0;
  unionfind UF(a);
  for (int i = n - 1; i >= 0; i--){
    ans[i] = mx;
    in[p[i]] = true;
    mx = max(mx, a[p[i]]);
    if (p[i] >= 1){
      if (in[p[i] - 1]){
        mx = max(mx, UF.unite(p[i] - 1, p[i]));
      }
    }
    if (p[i] < n - 1){
      if (in[p[i] + 1]){
        mx = max(mx, UF.unite(p[i], p[i] + 1));
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }
}