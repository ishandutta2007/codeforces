#include <bits/stdc++.h>
using namespace std;
const long long M30 = ((long long) 1 << 30) - 1;
const long long M31 = ((long long) 1 << 31) - 1;
const long long MOD = ((long long) 1 << 61) - 1;
const long long BASE = 10000000;
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
  monoid(char c){
    hash = c;
    mul = BASE;
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.hash = modulo(L.hash + mul(R.hash, L.mul));
  ans.mul = mul(L.mul, R.mul);
  return ans;
}
struct segment_tree{
  int N;
  vector<vector<monoid>> ST;
  segment_tree(string S){
    N = S.size();
    ST = vector<vector<monoid>>(N * 2 - 1);
    for (int i = 0; i < N; i++){
      ST[N - 1 + i].push_back(monoid(S[i]));
    }
    for (int i = N - 2; i >= 0; i--){
      int cnt = ST[i * 2 + 1].size();
      for (int j = 0; j < cnt; j++){
        ST[i].push_back(f(ST[i * 2 + 1][j], ST[i * 2 + 2][j]));
      }
      for (int j = 0; j < cnt; j++){
        ST[i].push_back(f(ST[i * 2 + 2][j], ST[i * 2 + 1][j]));
      }
    }
  }
  monoid range_fold(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return monoid();
    } else if (L <= l && r <= R){
      assert(x < ST[i].size());
      return ST[i][x];
    } else {
      int p = (r - l) / 2;
      int m = (l + r) / 2;
      if ((x & p) == 0){
        monoid resL = range_fold(L, R, x, i * 2 + 1, l, m);
        monoid resR = range_fold(L, R, x, i * 2 + 2, m, r);
        return f(resL, resR);
      } else {
        x ^= p;
        monoid resL;
        if (R >= m){
          resL = range_fold(max(L, m) - p, R - p, x, i * 2 + 1, l, m);
        }
        monoid resR;
        if (L < m){
          resR = range_fold(L + p, min(R, m) + p, x, i * 2 + 2, m, r);
        }
        return f(resR, resL);
      }
    }
  }
  monoid range_fold(int L, int R, int x){
    return range_fold(L, R, x, 0, 0, N);
  }
};
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  segment_tree ST(s);
  int best = 0;
  for (int i = 1; i < (1 << n); i++){
    int tv = 0, fv = (1 << n) + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      long long hash1 = ST.range_fold(0, mid, best).hash;
      long long hash2 = ST.range_fold(0, mid, i).hash;
      if (hash1 == hash2){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    if (tv != (1 << n)){
      if (s[i ^ tv] < s[best ^ tv]){
        best = i;
      }
    }
  }
  for (int i = 0; i < (1 << n); i++){
    cout << s[i ^ best];
  }
  cout << endl;
}