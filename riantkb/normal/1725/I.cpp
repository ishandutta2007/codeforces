#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
struct unionfind{
  vector<int> p;
  unionfind(int N){
    p = vector<int>(N, -1);
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -p[root(x)];
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      if (p[x] < p[y]){
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
};
int main(){
  int N;
  cin >> N;
  vector<int> U(N - 1), V(N - 1);
  for (int i = 0; i < N - 1; i++){
    cin >> U[i] >> V[i];
    U[i]--;
    V[i]--;
  }
  unionfind UF(N);
  long long ans = 1;
  for (int i = 0; i < N - 1; i++){
    int x = UF.size(U[i]);
    int y = UF.size(V[i]);
    ans *= x;
    ans %= MOD;
    ans *= y;
    ans %= MOD;
    UF.unite(U[i], V[i]);
  }
  ans *= ans;
  ans %= MOD;
  for (int i = 1; i <= N * 2 - 3; i += 2){
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
}