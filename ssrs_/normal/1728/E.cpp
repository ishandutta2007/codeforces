#include <bits/stdc++.h>
using namespace std;
tuple<int, int, int> ext_gcd(int a, int b){
  if (a > b){
    tuple<int, int, int> S = ext_gcd(b, a);
    swap(get<0>(S), get<1>(S));
    return S;
  } else if (b % a == 0){
    return make_tuple(1, 0, a);
  } else {
    tuple<int, int, int> S = ext_gcd(b % a, a);
    get<1>(S) -= get<0>(S) * (b / a);
    swap(get<0>(S), get<1>(S));
    return S;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  long long S = 0;
  for (int i = 0; i < n; i++){
    S += b[i];
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    d[i] = a[i] - b[i];
  }
  sort(d.begin(), d.end(), greater<int>());
  vector<long long> T(n + 1);
  T[0] = S;
  for (int i = 0; i < n; i++){
    T[i + 1] = T[i] + d[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (d[i] > 0){
      cnt++;
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    tuple<int, int, int> G = ext_gcd(x, y);
    if (n % get<2>(G) != 0){
      cout << -1 << "\n";
    } else {
      int g = get<2>(G);
      int x2 = x / g;
      int y2 = y / g;
      int n2 = n / g;
      if (get<0>(G) < 0){
        get<0>(G) += y2;
        get<1>(G) -= x2;
      }
      long long A = (long long) get<0>(G) * n2;
      long long B = (long long) get<1>(G) * n2;
      long long r = A / y2;
      A -= r * y2;
      B += r * x2;
      if (B < 0){
        cout << -1 << "\n";
      } else {
        int L = A * x;
        int R = (A + (B / x2) * y2) * x;
        if (L == R){
          cout << T[L] << "\n";
        } else if (cnt < L){
          cout << T[L] << "\n";
        } else if (R < cnt){
          cout << T[R] << "\n";
        } else {
          int L2 = L + (cnt - L) / (x * y2) * (x * y2);
          int R2 = L2 + x * y2;
          if (R2 > R){
            cout << T[L2] << "\n";
          } else {
            cout << max(T[L2], T[R2]) << "\n";
          }
        }
      }
    }
  }
}