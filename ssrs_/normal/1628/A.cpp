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
    vector<int> cnt(n + 1, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int mex = 0;
    for (int j = 0; j <= n; j++){
      if (cnt[j] == 0){
        mex = j;
        break;
      }
    }
    int p = 0;
    vector<int> ans;
    while (p < n){
      vector<bool> s(mex, false);
      int c = 0;
      int mex2 = mex;
      while (p < n){
        if (a[p] < mex){
          if (!s[a[p]]){
            c++;
          }
          s[a[p]] = true;
        }
        cnt[a[p]]--;
        if (cnt[a[p]] == 0){
          mex2 = min(mex2, a[p]);
        }
        p++;
        if (c == mex){
          break;
        }
      }
      ans.push_back(mex);
      mex = mex2;
    }
    int m = ans.size();
    cout << m << endl;
    for (int j = 0; j < m; j++){
      cout << ans[j];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}