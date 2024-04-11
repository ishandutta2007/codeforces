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
    vector<int> cnt(101, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int ans = 0;
    for (int j = 0; j < 101; j++){
      if (cnt[j] < 2){
        ans += j;
        break;
      }
    }
    for (int j = 0; j < 101; j++){
      if (cnt[j] < 1){
        ans += j;
        break;
      }
    }
    cout << ans << endl;
  }
}