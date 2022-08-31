#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    sort(cnt.rbegin(), cnt.rend());
    int tv = 0;
    int fv = n;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<int> cnt2(n, 0);
      for (int j = 0; j < n; j++){
        cnt2[j % (mid + 1)]++;
      }
      bool ok = true;
      for (int j = 0; j < mid; j++){
        if (cnt[j] > cnt2[j]){
          ok = false;
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