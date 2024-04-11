#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long W;
    cin >> n >> W;
    vector<int> w(n);
    for (int j = 0; j < n; j++){
      cin >> w[j];
    }
    vector<pair<int, int>> P;
    for (int j = 0; j < n; j++){
      if (w[j] <= W){
        P.push_back(make_pair(w[j], j));
      }
    }
    sort(P.rbegin(), P.rend());
    int m = P.size();
    long long sum = 0;
    vector<int> ans;
    for (int j = 0; j < m; j++){
      if (sum + P[j].first <= W){
        sum += P[j].first;
        ans.push_back(P[j].second);
      }
    }
    if (sum >= (W + 1) / 2){
      cout << ans.size() << endl;
      int s = ans.size();
      for (int j = 0; j < s; j++){
        cout << ans[j] + 1;
        if (j < s - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
}