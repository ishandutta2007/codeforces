#include <bits/stdc++.h>
using namespace std;
long long ap(long long a, long long b){
  return (b + a) * (b - a + 1) / 2;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> k(n);
    for (int j = 0; j < n; j++){
      cin >> k[j];
    }
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    for (int j = n - 2; j >= 0; j--){
      h[j] = max(h[j], h[j + 1] - (k[j + 1] - k[j]));
    }
    long long ans = ap(1, h[0]);
    long long P = h[0];
    for (int j = 1; j < n; j++){
      if (h[j] <= k[j] - k[j - 1]){
        ans += ap(1, h[j]);
        P = h[j];
      } else {
        ans += ap(P + 1, P + k[j] - k[j - 1]);
        P += k[j] - k[j - 1];
      }
    }
    cout << ans << endl;
  }
}