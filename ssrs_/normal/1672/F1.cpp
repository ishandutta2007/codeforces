#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int mx = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, cnt[j]);
    }
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(a[j], j);
    }
    sort(P.begin(), P.end());
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      b[P[(j + mx) % n].second] = P[j].first;
    }
    for (int j = 0; j < n; j++){
      cout << b[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}