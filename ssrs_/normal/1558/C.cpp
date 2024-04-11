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
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (j % 2 != a[j] % 2){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      vector<int> ans;
      for (int j = 0; j < n / 2; j++){
        int x = n - 1 - j * 2;
        int y = x - 1;
        int px = find(a.begin(), a.end(), x) - a.begin();
        int py = find(a.begin(), a.end(), y) - a.begin();
        if (px > py){
          ans.push_back(px + 1);
          reverse(a.begin(), a.begin() + px + 1);
          py = px - py;
          px = 0;
        }
        if (px > 0){
          ans.push_back(px + 1);
          reverse(a.begin(), a.begin() + px + 1);
          px = 0;
        }
        if (py - px > 1){
          ans.push_back(py);
          reverse(a.begin(), a.begin() + py);
        }
        ans.push_back(py + 2);
        reverse(a.begin(), a.begin() + py + 2);
        ans.push_back(3);
        reverse(a.begin(), a.begin() + 3);
        ans.push_back(n - j * 2);
        reverse(a.begin(), a.begin() + (n - j * 2));
      }
      int m = ans.size();
      cout << m << endl;
      for (int i = 0; i < m; i++){
        cout << ans[i];
        if (i < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
      for (int j = 0; j < n; j++){
        assert(a[j] == j);
      }
    }
  }
}