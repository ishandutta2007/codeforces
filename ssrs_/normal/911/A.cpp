#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mn = INF;
  for (int i = 0; i < n; i++){
    mn = min(mn, a[i]);
  }
  vector<int> p;
  for (int i = 0; i < n; i++){
    if (a[i] == mn){
      p.push_back(i);
    }
  }
  int m = p.size();
  int ans = n;
  for (int i = 0; i < m - 1; i++){
    ans = min(ans, p[i + 1] - p[i]);
  }
  cout << ans << endl;
}