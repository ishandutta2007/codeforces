#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> r(n);
    for (int j = 0; j < n; j++){
      cin >> r[j];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    int mx1 = 0;
    int sum1 = 0;
    for (int j = 0; j < n; j++){
      sum1 += r[j];
      mx1 = max(mx1, sum1);
    }
    int mx2 = 0;
    int sum2 = 0;
    for (int j = 0; j < m; j++){
      sum2 += b[j];
      mx2 = max(mx2, sum2);
    }
    cout << mx1 + mx2 << endl;
  }
}