#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    string b;
    cin >> b;
    vector<int> cnt1(26, 0);
    for (int j = 0; j < n; j++){
      cnt1[a[j] - 'a']++;
    }
    vector<int> cnt2(26, 0);
    for (int j = 0; j < n; j++){
      cnt2[b[j] - 'a']++;
    }
    bool ok = true;
    for (int j = 0; j < 25; j++){
      if (cnt1[j] < cnt2[j]){
        ok = false;
      } else {
        int d = cnt1[j] - cnt2[j];
        if (d % k != 0){
          ok = false;
        } else {
          cnt1[j + 1] += d;
        }
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}