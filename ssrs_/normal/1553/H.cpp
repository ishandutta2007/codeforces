#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> ans(1 << k, INF);
  for (int i = 0; i < k; i++){
    vector<int> d(1 << (i + 1), INF);
    for (int j = 0; j < (1 << k); j += (1 << (i + 1))){
      int L = j, M = j + (1 << i), R = j + (1 << (i + 1));
      int p1 = lower_bound(a.begin(), a.end(), L) - a.begin();
      int p2 = lower_bound(a.begin(), a.end(), M) - a.begin();
      int p3 = lower_bound(a.begin(), a.end(), R) - a.begin();
      if (p1 != p2 && p2 != p3){
        vector<int> t1(1 << i, INF);
        for (int l = p1; l < p2; l++){
          t1[a[l] & ((1 << i) - 1)] = 0;
        }
        for (int l = 0; l < i; l++){
          for (int m = 0; m < (1 << i); m++){
            t1[m] = min(t1[m], t1[m ^ (1 << l)] + (1 << l));
          }
        }
        reverse(t1.begin(), t1.end());
        vector<int> t2(1 << i, INF);
        for (int l = p2; l < p3; l++){
          t2[a[l] & ((1 << i) - 1)] = 0;
        }
        for (int l = 0; l < i; l++){
          for (int m = 0; m < (1 << i); m++){
            t2[m] = min(t2[m], t2[m ^ (1 << l)] + (1 << l));
          }
        }
        for (int l = 0; l < (1 << i); l++){
          int D = t1[l] + t2[l] + 1;
          d[l] = min(d[l], D);
          d[(1 << (i + 1)) - 1 - l] = min(d[(1 << (i + 1)) - 1 - l], D);
        }
      }
    }
    for (int j = 0; j < (1 << k); j++){
      ans[j] = min(ans[j], d[j & ((1 << (i + 1)) - 1)]);
    }
  }
  for (int i = 0; i < (1 << k); i++){
    cout << ans[i];
    if (i < (1 << k) - 1){
      cout << ' ';
    }
  }
  cout << endl;
}