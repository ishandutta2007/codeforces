#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  a[0] = 0;
  b[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> a[i] >> b[i];
  }
  vector<int> L, R;
  int cnt = 0;
  for (int i = 0; i < n; i++){
    int c = max(a[i], b[i]);
    int d = min(a[i + 1], b[i + 1]);
    if (c <= d){
      L.push_back(c);
      R.push_back(d);
      cnt++;
    }
  }
  int curr = -1, ans = 0;
  for (int i = 0; i < cnt; i++){
    ans += R[i] - max(curr, L[i]) + 1;
    curr = R[i] + 1;
  }
  cout << ans << endl;
}