#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> ext_gcd(int a, int b){
  if (a > b){
    pair<long long, long long> S = ext_gcd(b, a);
    return make_pair(S.second, S.first);
  }
  if (a == 1){
    return make_pair(1, 0);
  } else {
    pair<long long, long long> S = ext_gcd(b % a, a);
    return make_pair(S.second - b / a * S.first, S.first);
  }
}
long long composite_modinv(long long a, long long MOD){
  long long tmp = ext_gcd(a, MOD).first;
  return (tmp % MOD + MOD) % MOD;
}
vector<long long> combination(int n, long long MOD){
  //nC0, nC1, ..., nCn
  if (MOD == 1){
    return vector<long long>(n + 1, 0);
  }
  int X = MOD;
  vector<int> F;
  for (int i = 2; i * i <= X; i++){
    if (X % i == 0){
      F.push_back(i);
      while (X % i == 0){
        X /= i;
      }
    }
  }
  if (X > 1){
    F.push_back(X);
  }
  int cnt = F.size();
  map<int, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[F[i]] = i;
  }
  vector<vector<long long>> POW(cnt, vector<long long>(n));
  for (int i = 0; i < cnt; i++){
    POW[i][0] = 1;
    for (int j = 0; j < n - 1; j++){
      POW[i][j + 1] = POW[i][j] * F[i] % MOD;
    }
  }
  vector<int> m(n + 1, -1);
  for (int i = 2; i <= n; i++){
    if (m[i] == -1){
      for (int j = i * 2; j <= n; j += i){
        m[j] = i;
      }
    }
  }
  vector<vector<int>> f(n + 1);
  for (int i = 1; i <= n; i++){
    int x = i;
    while (m[x] != -1){
      f[i].push_back(m[x]);
      x /= m[x];
    }
    if (x > 1){
      f[i].push_back(x);
    }
  }
  vector<long long> INV(n + 1, -1);
  for (int i = 1; i <= n; i++){
    if (gcd(MOD, i) == 1){
      INV[i] = composite_modinv(i, MOD);
    }
  }
  long long s = 1;
  vector<int> e(cnt, 0);
  vector<long long> ans(n + 1);
  ans[0] = 1;
  for (int i = 0; i < n; i++){
    for (int x : f[n - i]){
      if (mp.count(x) == 0){
        s *= x;
        s %= MOD;
      } else {
        int id = mp[x];
        e[id]++;
      }
    }
    for (int x : f[i + 1]){
      if (mp.count(x) == 0){
        s *= INV[x];
        s %= MOD;
      } else {
        int id = mp[x];
        e[id]--;
      }
    }
    ans[i + 1] = s;
    for (int j = 0; j < cnt; j++){
      ans[i + 1] *= POW[j][e[j]];
      ans[i + 1] %= MOD;
    }
  }
  return ans;
}
vector<long long> combination2(int n, int k, long long MOD){
  //nCn, (n+1)Cn, ..., (n+k)Cn
  if (MOD == 1){
    return vector<long long>(k + 1, 0);
  }
  int X = MOD;
  vector<int> F;
  for (int i = 2; i * i <= X; i++){
    if (X % i == 0){
      F.push_back(i);
      while (X % i == 0){
        X /= i;
      }
    }
  }
  if (X > 1){
    F.push_back(X);
  }
  int cnt = F.size();
  map<int, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[F[i]] = i;
  }
  vector<vector<long long>> POW(cnt, vector<long long>(n + k));
  for (int i = 0; i < cnt; i++){
    POW[i][0] = 1;
    for (int j = 0; j < n + k - 1; j++){
      POW[i][j + 1] = POW[i][j] * F[i] % MOD;
    }
  }
  vector<int> m(n + k + 1, -1);
  for (int i = 2; i <= n + k; i++){
    if (m[i] == -1){
      for (int j = i * 2; j <= n + k; j += i){
        m[j] = i;
      }
    }
  }
  vector<vector<int>> f(n + k + 1);
  for (int i = 1; i <= n + k; i++){
    int x = i;
    while (m[x] != -1){
      f[i].push_back(m[x]);
      x /= m[x];
    }
    if (x > 1){
      f[i].push_back(x);
    }
  }
  vector<long long> INV(k + 1, -1);
  for (int i = 1; i <= k; i++){
    if (gcd(MOD, i) == 1){
      INV[i] = composite_modinv(i, MOD);
    }
  }
  long long s = 1;
  vector<int> e(cnt, 0);
  vector<long long> ans(k + 1);
  ans[0] = 1;
  for (int i = 0; i < k; i++){
    for (int x : f[n + i + 1]){
      if (mp.count(x) == 0){
        s *= x;
        s %= MOD;
      } else {
        int id = mp[x];
        e[id]++;
      }
    }
    for (int x : f[i + 1]){
      if (mp.count(x) == 0){
        s *= INV[x];
        s %= MOD;
      } else {
        int id = mp[x];
        e[id]--;
      }
    }
    ans[i + 1] = s;
    for (int j = 0; j < cnt; j++){
      ans[i + 1] *= POW[j][e[j]];
      ans[i + 1] %= MOD;
    }
  }
  return ans;
}
int main(){
  int n, p, l, r;
  cin >> n >> p >> l >> r;
  r++;
  vector<long long> A = combination(n, p);
  vector<long long> B = combination2(n, n + r + 1, p);
  vector<long long> f(n * 3 + 1, 0);
  for (int i = 0; i <= n; i++){
    f[i * 3] = A[i];
    if (i % 2 == 1){
      f[i * 3] = (p - f[i * 3]) % p;
    }
  }
  vector<long long> f2(n * 3 + 3, 0);
  for (int i = 0; i <= n * 3; i++){
    f2[i] += p - f[i];
    f2[i] %= p;
    f2[i + 2] += f[i];
    f2[i] %= p;
  }
  long long ans1 = 0;
  for (int i = 0; i <= n + l + 1; i++){
    ans1 += f2[i] * B[n + l + 1 - i] % p;
    ans1 %= p;
  }
  long long ans2 = 0;
  for (int i = 0; i <= n + r + 1; i++){
    ans2 += f2[i] * B[n + r + 1 - i] % p;
    ans2 %= p;
  }
  cout << (ans2 - ans1 + p) % p << endl;
}