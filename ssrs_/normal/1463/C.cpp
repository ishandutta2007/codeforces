#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<long long> t(n), x(n);
    for (int j = 0; j < n; j++){
      cin >> t[j] >> x[j];
    }
    vector<tuple<long long, long long, int>> P;
    long long com = 0;
    long long curr = 0;
    P.push_back(make_tuple(0, 0, 0));
    while (com < n){
      if (get<0>(P.back()) == t[com]){
        P.pop_back();
      }
      if (x[com] > curr){
        P.push_back(make_tuple(t[com], curr, 1));
      } else if (x[com] < curr){
        P.push_back(make_tuple(t[com], curr, -1));
      }
      long long d = abs(x[com] - curr);
      if (d > 0){
        P.push_back(make_tuple(t[com] + d, x[com], 0));
      }
      curr = x[com];
      if (d == 0){
        com = com + 1;
      } else {
        com = lower_bound(t.begin(), t.end(), t[com] + d) - t.begin();
      }
    }
    int sz = 0;
    t.push_back(INF);
    int ans = 0;
    for (int i = 0; i < n; i++){
      auto left = upper_bound(P.begin(), P.end(), make_tuple(t[i], INF, INF)) - 1;
      long long lp = get<1>(*left) + (t[i] - get<0>(*left)) * get<2>(*left);
      auto right = upper_bound(P.begin(), P.end(), make_tuple(t[i + 1], INF, INF)) - 1;
      long long rp = get<1>(*right) + (t[i + 1] - get<0>(*right)) * get<2>(*right);
      if (lp <= x[i] && x[i] <= rp || rp <= x[i] && x[i] <= lp){
        ans++;
      }
    }
    cout << ans << endl;
  }
}