#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  for (int i = 0; i < m; i++){
    int f = lower_bound(S.begin(), S.end(), b[i]) - S.begin();
    long long k = b[i] - S[f - 1];
    cout << f << ' ' << k << endl;
  }
}