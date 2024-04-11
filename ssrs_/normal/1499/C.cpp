#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    vector<long long> S(n);
    vector<long long> mn(n);
    for (int j = 0; j < n; j++){
      S[j] = c[j];
      mn[j] = c[j];
    }
    for (int j = 2; j < n; j++){
      S[j] += S[j - 2];
      mn[j] = min(mn[j], mn[j - 2]);
    }
    long long ans = INF;
    for (int j = 1; j < n; j++){
      int a = (j + 1) / 2;
      long long A = S[j - 1] + mn[j - 1] * (n - a);
      int b = (j + 2) / 2;
      long long B = S[j] + mn[j] * (n - b);
      ans = min(ans, A + B);
    }
    cout << ans << endl;
  }
}