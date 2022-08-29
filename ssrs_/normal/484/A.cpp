#include <bits/stdc++.h>
using namespace std;
pair<int, long long> f(pair<int, long long> a, pair<int, long long> b){
  if (a.first != b.first){
    return max(a, b);
  } else {
    return min(a, b);
  }
}
pair<int, long long> dfs(long long L, long long R, long long l, long long r){
  if (r <= L || R <= l){
    return make_pair(-1, 0);
  } else if (L <= l && r <= R){
    return make_pair(__builtin_popcountll(r - 1), r - 1);
  } else {
    long long m = (l + r) / 2;
    return f(dfs(L, R, l, m), dfs(L, R, m, r));
  }
}
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    long long l, r;
    cin >> l >> r;
    r++;
    pair<int, long long> P = dfs(l, r, 0, (long long) 1 << 60);
    cout << P.second << endl;
  }
}