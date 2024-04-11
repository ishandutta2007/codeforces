#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> x(m), w(m);
    for (int j = 0; j < m; j++){
      cin >> x[j] >> w[j];
    }
    vector<tuple<int, int, int>> P(m);
    for (int j = 0; j < m; j++){
      P[j] = make_tuple(w[j], x[j], j);
    }
    sort(P.begin(), P.end());
    vector<pair<int, int>> P2(n * 2);
    for (int j = 0; j < n * 2; j++){
      P2[j] = make_pair(get<1>(P[j]), get<2>(P[j]));
    }
    sort(P2.begin(), P2.end());
    long long sum = 0;
    for (int j = 0; j < n * 2; j++){
      sum += get<0>(P[j]);
    }
    cout << sum << "\n";
    for (int j = 0; j < n; j++){
      cout << P2[j].second + 1 << ' ' << P2[n * 2 - 1 - j].second + 1 << "\n";
    }
  }
}