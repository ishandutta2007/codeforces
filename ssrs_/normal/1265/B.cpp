#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> q(n);
    for (int j = 0; j < n; j++){
      q[p[j]] = j;
    }
    int mx = 0, mn = n;
    for (int j = 0; j < n; j++){
      mx = max(mx, q[j]);
      mn = min(mn, q[j]);
      if (mx - mn == j){
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << endl;
  }
}