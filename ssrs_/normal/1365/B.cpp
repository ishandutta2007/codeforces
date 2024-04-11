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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> cnt(2, 0);
    for (int j = 0; j < n; j++){
      cnt[b[j]]++;
    }
    if (cnt[0] != 0 && cnt[1] != 0){
      cout << "Yes" << endl;
    } else {
      bool ok = true;
      for (int j = 0; j < n - 1; j++){
        if (a[j] > a[j + 1]){
          ok = false;
          break;
        }
      }
      if (ok){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}