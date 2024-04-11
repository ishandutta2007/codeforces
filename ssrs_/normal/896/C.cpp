#include <bits/stdc++.h>
using namespace std;
long long seed;
long long rnd(){
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
long long modpow(long long a, long long b, long long mod){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2;
  }
  return ans;
}
int main(){
  int n, m, vmax;
  cin >> n >> m >> seed >> vmax;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    a[i] = rnd() % vmax + 1;
  }
  vector<tuple<long long, int, int>> T(n);
  for (int i = 0; i < n; i++){
    T[i] = make_tuple(a[i], i, i + 1);
  }
  for (int i = 0; i < m; i++){
    int t = rnd() % 4 + 1;
    int l = rnd() % n + 1;
    int r = rnd() % n + 1;
    if (l > r){
      swap(l, r);
    }
    l--;
    if (t == 1 || t == 2){
      int x = rnd() % vmax + 1;
      vector<tuple<long long, int, int>> T2;
      int cnt = T.size();
      for (int j = 0; j < cnt; j++){
        long long A = get<0>(T[j]);
        int L = get<1>(T[j]);
        int R = get<2>(T[j]);
        if (L < l){
          T2.push_back(make_tuple(A, L, min(l, R)));
        }
        if (max(L, l) < min(R, r)){
          if (t == 1){
            T2.push_back(make_tuple(A + x, max(L, l), min(R, r)));
          } else {
            T2.push_back(make_tuple(x, max(L, l), min(R, r)));
          }
        }
        if (r < R){
          T2.push_back(make_tuple(A, max(L, r), R));
        }
      }
      int cnt2 = T2.size();
      vector<tuple<long long, int, int>> T3;
      T3.push_back(T2[0]);
      for (int j = 1; j < cnt2; j++){
        if (get<0>(T2[j - 1]) == get<0>(T2[j])){
          get<2>(T3.back()) = get<2>(T2[j]);
        } else {
          T3.push_back(T2[j]);
        }
      }
      swap(T, T3);
    }
    if (t == 3){
      int x = rnd() % (r - l);
      int cnt = T.size();
      vector<pair<long long, int>> P;
      for (int j = 0; j < cnt; j++){
        long long A = get<0>(T[j]);
        int L = get<1>(T[j]);
        int R = get<2>(T[j]);
        int d = min(R, r) - max(L, l);
        if (d > 0){
          P.push_back(make_pair(A, d));
        }
      }
      sort(P.begin(), P.end());
      int cnt2 = P.size();
      for (int j = 0; j < cnt2; j++){
        if (x >= P[j].second){
          x -= P[j].second;
        } else {
          cout << P[j].first << "\n";
          break;
        }
      }
    }
    if (t == 4){
      int x = rnd() % vmax + 1;
      int y = rnd() % vmax + 1;
      int cnt = T.size();
      long long ans = 0;
      vector<pair<long long, int>> P;
      for (int j = 0; j < cnt; j++){
        long long A = get<0>(T[j]);
        int L = get<1>(T[j]);
        int R = get<2>(T[j]);
        int d = min(R, r) - max(L, l);
        if (d > 0){
          ans += modpow(A % y, x, y) * d;
          ans %= y;
        }
      }
      cout << ans << "\n";
    }
  }
}