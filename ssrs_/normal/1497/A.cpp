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
    vector<int> b;
    for (int j = 0; j <= 100; j++){
      if (cnt[j] > 0){
        b.push_back(j);
        cnt[j]--;
      } else {
        break;
      }
    }
    for (int j = 0; j <= 100; j++){
      for (int k = 0; k < cnt[j]; k++){
        b.push_back(j);
      }
    }
    for (int j = 0; j < n; j++){
      cout << b[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}