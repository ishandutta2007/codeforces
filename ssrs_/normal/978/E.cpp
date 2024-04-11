#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  int mn = 0, mx = INF;
  for (int i = 0; i <= n; i++){
    mn = max(mn, - S[i]);
    mx = min(mx, w - S[i]);
  }
  cout << max(mx - mn + 1, 0) << endl;
}