#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  long long ans = INF;
  for (int i = 1; i < n; i++){
    for (int j = i + 1; j <= n; j++){
      if (j - i > 10000){
        break;
      }
      ans = min(ans, (long long) (j - i) * (j - i) + (S[j] - S[i]) * (S[j] - S[i]));
    }
  }
  cout << ans << endl;
}