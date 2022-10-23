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
    vector<pair<int, int>> P(n - 1);
    for (int j = 0; j < n - 1; j++){
      P[j] = make_pair(a[j] - a[j + 1], j);
    }
    sort(P.begin(), P.end());
    vector<int> x(n);
    x[0] = 0;
    for (int j = 0; j < n - 1; j++){
      x[j + 1] = P[j].second + 1;
    }
    for (int j = 0; j < n; j++){
      cout << x[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}