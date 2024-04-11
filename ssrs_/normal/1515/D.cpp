#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
      c[j]--;
    }
    if (r > l){
      vector<int> c2;
      for (int j = l; j < n; j++){
        c2.push_back(c[j]);
      }
      for (int j = 0; j < l; j++){
        c2.push_back(c[j]);
      }
      swap(c, c2);
      swap(l, r);
    }
    vector<int> cnt1(n, 0), cnt2(n, 0);
    for (int j = 0; j < l; j++){
      cnt1[c[j]]++;
    }
    for (int j = l; j < n; j++){
      cnt2[c[j]]++;
    }
    int sum = 0;
    int p = 0;
    for (int j = 0; j < n; j++){
      sum += min(cnt1[j], cnt2[j]);
      if (cnt1[j] > cnt2[j]){
        p += (cnt1[j] - cnt2[j]) / 2;
      }
    }
    sum += min(p, (l - r) / 2);
    cout << n / 2 - sum + (l - r) / 2 << endl;
  }
}