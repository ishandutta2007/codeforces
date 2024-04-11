#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++){
    b[i] = max(a[i] - a[i + 1], 0);
  }
  vector<long long> S(n);
  S[0] = 0;
  for (int i = 0; i < n - 1; i++){
    S[i + 1] = S[i] + b[i];
  }
  vector<int> c(n - 1);
  for (int i = 0; i < n - 1; i++){
    c[i] = max(a[i + 1] - a[i], 0);
  }
  vector<long long> T(n);
  T[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--){
    T[i] = T[i + 1] + c[i];
  }
  for (int i = 0; i < m; i++){
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (s < t){
      cout << S[t] - S[s] << endl;
    } else {
      cout << T[t] - T[s] << endl;
    }
  }
}