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
    vector<int> cnt(3, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int sum = cnt[1] + cnt[2] * 2;
    if (sum % 2 == 1){
      cout << "NO" << endl;
    } else {
      if (cnt[1] == 0 && cnt[2] % 2 == 1){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}