#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  int k, n;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  long long sum = 0;
  for (int i = 0; i <= n - k; i++){
    sum += S[i + k] - S[i];
  }
  cout << (double) sum / (n - k + 1) << endl;
}