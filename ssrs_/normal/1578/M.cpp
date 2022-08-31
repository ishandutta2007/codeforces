#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  for (int i = 0; i < n; i++){
    for (int j = 1; j < m; j += 2){
      s[i][j] = 'A' + ('Z' - s[i][j]);
    }
  }
  vector<pair<string, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(s[i], i);
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < n; i++){
    cout << P[i].second + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}