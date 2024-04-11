#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> a(3);
  for (int i = 0; i < 3; i++){
    cin >> a[i];
  }
  vector<int> c1(n + 1, 0);
  for (int i = 0; i < n; i++){
    c1[i + 1] = c1[i];
    for (int j = 0; j < 3; j++){
      if (a[j][i] == '1'){
        c1[i + 1]++;
        if (j > 0){
          if (a[j - 1][i] == '1'){
            c1[i + 1]--;
          }
        }
      }
    }
  }
  vector<int> c2(n, 0);
  for (int i = 0; i < n - 1; i++){
    c2[i + 1] = c2[i];
    for (int j = 0; j < 3; j++){
      if (a[j][i] == '1' && a[j][i + 1] == '1'){
        c2[i + 1]++;
        if (j > 0){
          if (a[j - 1][i] == '1' && a[j - 1][i + 1] == '1'){
            c2[i + 1]--;
          }
        }
      }
    }
  }
  vector<int> p;
  for (int i = 0; i < n; i++){
    if (a[0][i] == '1' && a[1][i] == '1' && a[2][i] == '1'){
      p.push_back(i);
    }
  }
  int cnt = p.size();
  vector<int> L, R;
  for (int i = 0; i < cnt - 1; i++){
    if (p[i + 1] - p[i] >= 2){
      bool ok = true;
      for (int j = p[i] + 1; j < p[i + 1]; j++){
        if (!(a[0][j] == '1' && a[1][j] == '0' && a[2][j] == '1')){
          ok = false;
        }
      }
      if (ok){
        L.push_back(p[i]);
        R.push_back(p[i + 1]);
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    int ans1 = c1[r] - c1[l];
    int ans2 = c2[r - 1] - c2[l];
    int p1 = lower_bound(L.begin(), L.end(), l) - L.begin();
    int p2 = lower_bound(R.begin(), R.end(), r) - R.begin();
    int ans3 = max(p2 - p1, 0);
    cout << ans1 - ans2 + ans3 << "\n";
  }
}