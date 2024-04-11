#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000001;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  b[0] = 0;
  vector<long long> c(n, 0);
  c[0] = 1;
  for (int i = 1; i <= n; i++){
    for (int j = i * 2; j <= n; j += i){
      a[j - 1] -= a[i - 1];
      b[j - 1] -= b[i - 1];
      c[j - 1] -= c[i - 1];
    }
  }
  vector<long long> imos1(MAX + 1, 0), imos2(MAX + 1, 0);
  for (int i = 0; i < n; i++){
    long long A = -c[i];
    long long B = a[i] - b[i];
    if (A < 0){
      A *= -1;
      B *= -1;
    }
    if (A == 0){
      B = abs(B);
      imos2[0] += B;
      imos2[MAX] -= B;
    } else if (B >= 0){
      imos1[0] += A;
      imos1[MAX] -= A;
      imos2[0] += B;
      imos2[MAX] -= B;
    } else {
      long long m = -B / A;
      if (m > MAX){
        imos1[0] -= A;
        imos1[MAX] += A;
        imos2[0] -= B;
        imos2[MAX] += B;
      } else {
        imos1[0] -= A;
        imos1[m + 1] += A;
        imos1[m + 1] += A;
        imos1[MAX] -= A;
        imos2[0] -= B;
        imos2[m + 1] += B;
        imos2[m + 1] += B;
        imos2[MAX] -= B;
      }
    }
  }
  for (int i = 0; i < MAX; i++){
    imos1[i + 1] += imos1[i];
    imos2[i + 1] += imos2[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int x;
    cin >> x;
    cout << imos1[x] * x + imos2[x] << endl;
  }
}