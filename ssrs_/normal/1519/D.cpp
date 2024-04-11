#include <bits/stdc++.h>
using namespace std;
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
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i] * b[i];
  }
  long long ans = sum;
  for (int i = 0; i < n; i++){
    long long tmp = sum;
    for (int j = 1; j <= min(i, n - 1 - i); j++){
      tmp -= a[i - j] * b[i - j];
      tmp -= a[i + j] * b[i + j];
      tmp += a[i - j] * b[i + j];
      tmp += a[i + j] * b[i - j];
      ans = max(ans, tmp);
    }
  }
  for (int i = 0; i < n - 1; i++){
    long long tmp = sum;
    for (int j = 1; j <= min(i + 1, n - 1 - i); j++){
      tmp -= a[i - j + 1] * b[i - j + 1];
      tmp -= a[i + j] * b[i + j];
      tmp += a[i - j + 1] * b[i + j];
      tmp += a[i + j] * b[i - j + 1];
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}