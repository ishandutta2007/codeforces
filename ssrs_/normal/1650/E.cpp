#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    a[0] = -1;
    for (int j = 1; j <= n; j++){
      cin >> a[j];
      a[j]--;
    }
    int tv = 0, fv = d;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<int> P;
      for (int j = 0; j < n; j++){
        if (a[j + 1] - a[j] <= mid){
          P.push_back(j);
        }
      }
      bool ok = false;
      if (P.empty()){
        ok = true;
      }
      if (P.size() <= 2){
        vector<int> c;
        for (int x : P){
          if (x != 0){
            c.push_back(x);
          }
          c.push_back(x + 1);
        }
        for (int x : c){
          int pr = -1;
          bool ok2 = true;
          for (int j = 1; j <= n; j++){
            if (j != x){
              if (a[j] - pr <= mid){
                ok2 = false;
              }
              pr = a[j];
            }
          }
          if (ok2){
            vector<pair<int, int>> imos;
            imos.push_back(make_pair(0, 0));
            imos.push_back(make_pair(d, 0));
            for (int j = 0; j <= n; j++){
              if (j != x){
                imos.push_back(make_pair(max(a[j] - mid, 0), 1));
                imos.push_back(make_pair(min(a[j] + mid + 1, d), -1));
              }
            }
            sort(imos.begin(), imos.end());
            int sum = 0;
            int p = 0;
            for (int j = 0; j < (n + 1) * 2; j++){
              if (p != imos[j].first && sum == 0){
                ok = true;
              }
              p = imos[j].first;
              sum += imos[j].second;
            }
          }
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}