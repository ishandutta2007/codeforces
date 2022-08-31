#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (k == 0){
    cout << n << endl;
    for (int i = 1; i <= n; i++){
      cout << i;
      if (i < n){
        cout << ' ';
      }
    }
    cout << endl;
  } else {
    vector<pair<int, int>> P(n);
    for (int i = 0; i < n; i++){
      P[i] = make_pair(a[i], i);
    }
    sort(P.begin(), P.end());
    for (int i = 0; i < n; i++){
      a[i] = P[i].first;
    }
    vector<int> id(n);
    for (int i = 0; i < n; i++){
      id[i] = P[i].second;
    }
    int c = 0;
    while ((1 << c) <= k){
      c++;
    }
    vector<int> p;
    p.push_back(0);
    for (int i = 1; i < n; i++){
      if ((a[i] >> c) != (a[i - 1] >> c)){
        p.push_back(i);
      }
    }
    int cnt = p.size();
    p.push_back(n);
    vector<int> b;
    k--;
    for (int i = 0; i < cnt; i++){
      int L = p[i], R = p[i + 1];
      int m = lower_bound(a.begin(), a.end(), (a[L] >> c << c) + (1 << (c - 1))) - a.begin();
      if (L == m || m == R){
        b.push_back(L);
      } else {
        bool ok = false;
        for (int j = L; j < m; j++){
          int x = a[j] >> c << c;
          for (int l = c - 1; l >= 0; l--){
            if ((k >> l & 1) == 0){
              int L2, R2;
              if ((a[j] >> l & 1) == 0){
                L2 = x | (1 << l);
                R2 = x + (1 << (l + 1));
              } else {
                L2 = x;
                R2 = x | (1 << l);
              }
              int q = lower_bound(a.begin() + m, a.begin() + R, L2) - a.begin();
              if (q < R){
                if (a[q] < R2){
                  b.push_back(j);
                  b.push_back(q);
                  ok = true;
                  break;
                }
              }
              if ((a[j] >> l & 1) == 1){
                x |= 1 << l;
              }
            } else {
              if ((a[j] >> l & 1) == 0){
                x |= 1 << l;
              }
            }
          }
          if (ok){
            break;
          }
        }
        if (!ok){
          b.push_back(L);
        }
      }
    }
    int l = b.size();
    if (l == 1){
      cout << -1 << endl;
    } else {
      cout << l << endl;
      for (int i = 0; i < l; i++){
        cout << id[b[i]] + 1;
        if (i < l - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}