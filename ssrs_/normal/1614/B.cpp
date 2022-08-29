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
    }
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(a[j], j);
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    vector<int> x(n + 1);
    x[0] = 0;
    long long T = 0;
    for (int j = 0; j < n; j++){
      int c = j / 2 + 1;
      x[P[j].second + 1] = c;
      if (j % 2 == 1){
        x[P[j].second + 1] *= -1;
      }
      T += (long long) c * P[j].first * 2;
    }
    cout << T << endl;
    for (int j = 0; j <= n; j++){
      cout << x[j];
      if (j < n){
        cout << ' ';
      }
    }
    cout << endl;
  }
}