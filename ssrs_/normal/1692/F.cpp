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
    vector<int> cnt(10, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j] % 10]++;
    }
    bool ok = false;
    if (cnt[1] >= 3){
      ok = true;
    }
    for (int j = 0; j < 10; j++){
      for (int k = 0; k < 10; k++){
        if (j != k && cnt[j] >= 2 && cnt[k] >= 1){
          if ((j * 2 + k) % 10 == 3){
            ok = true;
          }
        }
      }
    }
    for (int j = 0; j < 10; j++){
      for (int k = j + 1; k < 10; k++){
        for (int l = k + 1; l < 10; l++){
          if (cnt[j] >= 1 && cnt[k] >= 1 && cnt[l] >= 1){
            if ((j + k + l) % 10 == 3){
              ok = true;
            }
          }
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}