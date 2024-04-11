#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    int mx = -1;
    vector<int> p;
    for (int j = 0; j < (1 << n); j++){
      long long sum = 0;
      vector<int> a(m, 0);
      for (int k = 0; k < n; k++){
        if ((j >> k & 1) == 0){
          sum -= x[k];
        } else {
          sum += x[k];
        }
        for (int l = 0; l < m; l++){
          if (s[k][l] == '1'){
            if ((j >> k & 1) == 0){
              a[l]++;
            } else {
              a[l]--;
            }
          }
        }
      }
      vector<pair<int, int>> P(m);
      for (int k = 0; k < m; k++){
        P[k] = make_pair(a[k], k);
      }
      sort(P.begin(), P.end());
      vector<int> pc(m);
      for (int k = 0; k < m; k++){
        pc[P[k].second] = k + 1;
        sum += P[k].first * (k + 1);
      }
      if (sum > mx){
        mx = sum;
        p = pc;
      }
    }
    for (int j = 0; j < m; j++){
      cout << p[j];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}