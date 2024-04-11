#include <bits/stdc++.h>
using namespace std;
const long long M30 = ((long long) 1 << 30) - 1;
const long long M31 = ((long long) 1 << 31) - 1;
const long long MOD = ((long long) 1 << 61) - 1;
long long BASE;
unsigned long long modulo(unsigned long long x){
  unsigned long long xu = x >> 61;
  unsigned long long xd = x & MOD;
  unsigned long long res = xu + xd;
  if (res >= MOD){
    res -= MOD;
  }
  return res;
}
unsigned long long mul(unsigned long long a, unsigned long long b){
  unsigned long long au = a >> 31;
  unsigned long long ad = a & M31;
  unsigned long long bu = b >> 31;
  unsigned long long bd = b & M31;
  unsigned long long mid = au * bd + ad * bu;
  unsigned long long midu = mid >> 30;
  unsigned long long midd = mid & M30;
  return modulo(au * bu * 2 + midu + (midd << 31) + ad * bd);
}
struct monoid{
  unsigned long long hash, mul;
  monoid(){
    hash = 0;
    mul = 1;
  }
  monoid(int x){
    hash = x;
    if (x >= 0){
      mul = BASE;
    } else {
      mul = 1;
    }
  }
};
monoid f(monoid L, monoid R){
  if (L.hash == -1){
    return R;
  }
  if (R.hash == -1){
    return L;
  }
  monoid ans;
  ans.hash = modulo(L.hash + mul(R.hash, L.mul));
  ans.mul = mul(L.mul, R.mul);
  return ans;
}
struct segment_tree{
  int N;
  array<vector<monoid>, 2> ST;
  segment_tree(){
  }
  segment_tree(vector<int> &k){
    int N2 = k.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    ST[0] = vector<monoid>(N * 2 - 1);
    ST[1] = vector<monoid>(N * 2 - 1);
    for (int i = 0; i < N2; i++){
      ST[0][N - 1 + i] = monoid(k[i]);
      ST[1][N - 1 + i] = monoid(k[i]);
    }
    for (int i = N - 2; i >= 0; i--){
      ST[0][i] = f(ST[0][i * 2 + 1], ST[0][i * 2 + 2]);
      ST[1][i] = f(ST[1][i * 2 + 2], ST[1][i * 2 + 1]);
    }
  }
  void update(int i, int c){
    i += N - 1;
    ST[0][i] = monoid(c);
    ST[1][i] = monoid(c);
    while (i > 0){
      i = (i - 1) / 2;
      ST[0][i] = f(ST[0][i * 2 + 1], ST[0][i * 2 + 2]);
      ST[1][i] = f(ST[1][i * 2 + 2], ST[1][i * 2 + 1]);
    }
  }
  monoid get(int d){
    return ST[d][0];
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
  BASE = mt() % 1000000000000000000;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<vector<int>> pos(n);
    for (int j = 0; j < n; j++){
      pos[a[j]].push_back(j);
    }
    segment_tree ST(a);
    bool ok = false;
    if (ST.get(0).hash == ST.get(1).hash){
      ok = true;
    }
    for (int j = 0; j < n; j++){
      for (int k : pos[j]){
        ST.update(k, -1);
      }
      if (ST.get(0).hash == ST.get(1).hash){
        ok = true;
      }
      for (int k : pos[j]){
        ST.update(k, j);
      }
    }
    if (ok){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}