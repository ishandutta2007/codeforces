#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int n, k, m;
  cin >> n >> k >> m;
  vector<string> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> meaning(n);
  vector<int> cost(k, INF);
  for (int i = 0; i < k; i++){
    int x;
    cin >> x;
    for (int j = 0; j < x; j++){
      int y;
      cin >> y;
      meaning[y - 1] = i;
      cost[i] = min(cost[i], a[y - 1]);
    }
  }
  map<string, int> mp;
  for (int i = 0; i < n; i++){
    mp[w[i]] = cost[meaning[i]];
  }
  long long ans = 0;
  for (int i = 0; i < m; i++){
    string s;
    cin >> s;
    ans += mp[s];
  }
  cout << ans << endl;
}