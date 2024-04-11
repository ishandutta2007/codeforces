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
  vector<long long> S(n, 0);
  for (int i = 0; i < n - 1; i++){
    if (i % 2 == 0){
      S[i + 1] = S[i] + a[i] * i * 2 + b[i] * (i * 2 + 1);
    } else {
      S[i + 1] = S[i] + a[i] * (i * 2 + 1) + b[i] * i * 2;
    }
  }
  vector<long long> Sa1(n, 0);
  vector<long long> Sa2(n, 0);
  Sa1[n - 1] = a[n - 1];
  Sa2[n - 1] = n * a[n - 1];
  for (int i = n - 2; i >= 0; i--){
    Sa1[i] = Sa1[i + 1] + a[i];
    Sa2[i] = Sa2[i + 1] + a[i] * (i + 1);
  }
  vector<long long> Sb1(n, 0);
  vector<long long> Sb2(n, 0);
  Sb1[n - 1] = b[n - 1];
  Sb2[n - 1] = n * b[n - 1];
  for (int i = n - 2; i >= 0; i--){
    Sb1[i] = Sb1[i + 1] + b[i];
    Sb2[i] = Sb2[i + 1] + b[i] * (i + 1);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    long long tmp = S[i];
    if (i % 2 == 0){
      tmp += Sa2[i];
      tmp += Sa1[i] * (i - 1);
      tmp += Sb1[i] * (n * 2 + i);
      tmp -= Sb2[i];
    } else {
      tmp += Sb2[i];
      tmp += Sb1[i] * (i - 1);
      tmp += Sa1[i] * (n * 2 + i);
      tmp -= Sa2[i];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}