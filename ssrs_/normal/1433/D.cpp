#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<pair<int, int>> p(n);
    for (int j = 0; j < n; j++){
      p[j] = make_pair(a[j], j);
    }
    sort(p.begin(), p.end());
    if (p[0].first == p[n - 1].first){
      cout << "NO" << endl;
    } else {
      vector<pair<int, int>> ans;
      bool ok = false;
      for (int j = 0; j < n; j++){
        if (p[j].first == p[n - 1].first){
          if (ok){
            ans.push_back(make_pair(p[j].second, p[0].second));
          }
          ok = true;
        } else {
          auto itr = upper_bound(p.begin(), p.end(), make_pair(p[j].first, INF));
          ans.push_back(make_pair(p[j].second, (*itr).second));
        }
      }
      cout << "YES" << endl;
      for (int j = 0; j < n - 1; j++){
        cout << ans[j].first + 1 << ' ' << ans[j].second + 1 << endl;
      }
    }
  }
}