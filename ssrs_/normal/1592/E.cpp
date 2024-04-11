#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  vector<int> C(1 << 20, INF);
  for (int i = 0; i < 20; i++){
    vector<int> p;
    p.push_back(-1);
    for (int j = 0; j < n; j++){
      if ((a[j] >> i & 1) == 0){
        p.push_back(j);
      }
    }
    p.push_back(n);
    int cnt = p.size();
    for (int j = 0; j < cnt - 1; j++){
      vector<int> b;
      for (int k = p[j] + 1; k < p[j + 1]; k++){
        b.push_back(a[k] >> i);
      }
      int m = b.size();
      vector<int> s(m + 1);
      s[0] = 0;
      for (int k = 0; k < m; k++){
        s[k + 1] = s[k] ^ b[k];
      }
      for (int j = 0; j <= m; j++){
        if (C[s[j]] == INF){
          C[s[j]] = j;
        } else {
          ans = max(ans, j - C[s[j]]);
        }
      }
      for (int j = 0; j <= m; j++){
        C[s[j]] = INF;
      }
    }
  }
  cout << ans << endl;
}