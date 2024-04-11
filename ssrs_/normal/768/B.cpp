#include <bits/stdc++.h>
using namespace std;
long long dfs(long long n, long long L, long long R, long long l, long long r){
  if (r <= L || R <= l){
    return 0;
  } else if (L <= l && r <= R){
    return n;
  } else {
    long long m1 = (l + r) / 2;
    long long m2 = (l + r + 1) / 2;
    long long ans = 0;
    ans += dfs(n / 2, L, R, l, m1);
    if (L <= m1 && m2 <= R){
      ans += n % 2;
    }
    ans += dfs(n / 2, L, R, m2, r);
    return ans;
  }
}
int main(){
  long long n, l, r;
  cin >> n >> l >> r;
  l--;
  if (n == 0){
    cout << 0 << endl;
  } else {
    long long d = 64 - __builtin_clzll(n);
    long long R = ((long long) 1 << d) - 1;
    cout << dfs(n, l, r, 0, R) << endl;
  }
}