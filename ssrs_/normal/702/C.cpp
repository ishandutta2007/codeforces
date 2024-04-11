#include <bits/stdc++.h>
using namespace std;
int INF = 2000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++){
    int tmp = INF;
    auto itr = lower_bound(b.begin(), b.end(), a[i]);
    if (itr != b.end()){
      tmp = min(tmp, abs((*itr) - a[i]));
    }
    if (itr != b.begin()){
      itr--;
      tmp = min(tmp, abs((*itr) - a[i]));
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}