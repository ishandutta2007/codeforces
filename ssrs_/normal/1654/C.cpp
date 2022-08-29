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
    map<long long, int> mp1;
    for (int j = 0; j < n; j++){
      mp1[a[j]]++;
    }
    long long S = 0;
    for (int j = 0; j < n; j++){
      S += a[j];
    }
    map<long long, long long> mp2;
    mp2[S] = 1;
    bool ok = true;
    while (!mp2.empty()){
      long long mx = (*prev(mp2.end())).first;
      long long cnt = (*prev(mp2.end())).second;
      long long cnt2;
      if (mp1.count(mx) == 0){
        cnt2 = 0;
      } else {
        cnt2 = mp1[mx];
      }
      if (cnt < cnt2){
        ok = false;
        break;
      }
      if (cnt > cnt2){
        if (mx == 1){
          ok = false;
          break;
        }
        mp2[mx / 2] += cnt - cnt2;
        mp2[(mx + 1) / 2] += cnt - cnt2;
      }
      if (mx == 1){
        break;
      }
      mp2.erase(prev(mp2.end()));
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}