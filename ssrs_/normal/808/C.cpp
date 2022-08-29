#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.begin(), P.end());
  vector<int> a2(n);
  for (int i = 0; i < n; i++){
    a2[i] = P[i].first;
  }
  vector<int> b(n);
  bool ok = true;
  int sum = 0;
  for (int i = 0; i < n; i++){
    b[i] = (a2[i] + 1) / 2;
    if (i > 0){
      b[i] = max(b[i], b[i - 1]);
    }
    if (b[i] > a2[i]){
      ok = false;
    }
    sum += b[i];
  }
  if (sum > w){
    ok = false;
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = n - 1; i >= 0; i--){
      while (b[i] < a2[i] && sum < w){
        sum++;
        b[i]++;
      }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
      ans[P[i].second] = b[i];
    }
    for (int i = 0; i < n; i++){
      cout << ans[i];
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}