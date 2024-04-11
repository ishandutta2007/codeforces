#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int x;
    cin >> x;
    for (int j = 0; j < n; j++){
      a[j] -= x;
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    long long mx = -INF;
    int ans = n;
    for (int j = 2; j <= n; j++){
      mx = max(mx, S[j - 2]);
      if (mx > S[j]){
        ans--;
        mx = -INF;
        j++;
      }
    }
    cout << ans << endl;
  }
}