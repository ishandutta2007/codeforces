#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
//https://qiita.com/drken/items/ae02240cd1f8edfc86fd
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
long long extGcd(long long a, long long b, long long &p, long long &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    long long d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
  long long p, q;
  long long d = extGcd(m1, m2, p, q);
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d);
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
    b[i]--;
  }
  int x = 2 * max(n, m);
  vector<int> A(x, -1);
  for (int i = 0; i < n; i++){
    A[a[i]] = i;
  }
  vector<int> B(x, -1);
  for (int i = 0; i < m; i++){
    B[b[i]] = i;
  }
  int g = gcd(n, m);
  vector<pair<long long, long long>> P;
  for (int i = 0; i < x; i++){
    if (A[i] != -1 && B[i] != -1){
      if (A[i] % g == B[i] % g){
        P.push_back(ChineseRem(A[i], n, B[i], m));
      }
    }
  }
  long long tv = INF, fv = 0;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    long long sum = mid;
    for (auto res : P){
      long long r = res.first, q = res.second;
      sum -= mid / q;
      if (mid % q > r){
        sum--;
      }
    }
    if (sum >= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << "\n";
}