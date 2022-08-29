#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> m(n);
  for (int i = 0; i < n; i++){
    cin >> m[i];
  }
  long long ans = 0;
  vector<int> F(n);
  for (int i = 0; i < n; i++){
    vector<int> f(n);
    for (int j = 0; j < n; j++){
      f[j] = 0;
    }
    f[i] = m[i];
    for (int j = i - 1; j >= 0; j--){
      f[j] = min(m[j], f[j + 1]);
    }
    for (int j = i + 1; j < n; j++){
      f[j] = min(m[j], f[j - 1]);
    }
    long long S = 0;
    for (int j = 0; j < n; j++){
      S += f[j];
    }
    if (S > ans){
      ans = S;
      for (int j = 0; j < n; j++){
        F[j] = f[j];
      }
    }
  }
  for (int j = 0; j < n - 1; j++){
    cout << F[j] << ' ';
  }
  cout << F[n - 1];
}