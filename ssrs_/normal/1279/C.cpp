#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<int> p(n, -1);
    for (int j = 0; j < n; j++){
      p[a[j]] = j;
    }
    for (int j = 0; j < m; j++){
      b[j] = p[b[j]];
    }
    long long ans = 0;
    int mx = 0;
    for (int j = 0; j < m; j++){
      if (b[j] <= mx){
        ans++;
      } else {
        ans += (b[j] - j) * 2 + 1;
        mx = max(mx, b[j]);
      }
    }
    cout << ans << endl;
  }
}