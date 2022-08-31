#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int n, L;
  cin >> n >> L;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  for (int i = 0; i < n - 1; i++){
    c[i + 1] = min(c[i + 1], c[i] * 2);
  }
  int x = n / 2, y = n - n / 2;
  vector<long long> A(1 << x, 0);
  for (int i = 0; i < (1 << x); i++){
    for (int j = 0; j < x; j++){
      if ((i >> j & 1) == 1){
        A[i] += c[j];
      }
    }
  }
  vector<long long> mn = A;
  for (int i = (1 << x) - 2; i >= 0; i--){
    mn[i] = min(mn[i], mn[i + 1]);
  }
  long long p = (long long) L / (1 << (n - 1)) * c[n - 1];
  L %= 1 << (n - 1);
  long long ans = INF;
  for (int i = 0; i < (1 << y); i++){
    long long s = 0;
    for (int j = 0; j < y; j++){
      if ((i >> j & 1) == 1){
        s += c[x + j];
      }
    }
    int t = i << x;
    if (t >= L){
      ans = min(ans, s);
    } else {
      int d = L - t;
      if (d < (1 << x)){
        ans = min(ans, s + mn[d]);
      }
    }
  }
  ans += p;
  cout << ans << endl;
}