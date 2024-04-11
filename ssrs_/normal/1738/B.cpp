#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int j = 0; j < k; j++){
      cin >> s[j];
    }
    bool ok = true;
    for (int j = 0; j < k - 2; j++){
      if (s[j + 1] - s[j] > s[j + 2] - s[j + 1]){
        ok = false;
      }
    }
    if (k >= 2){
      int d = s[1] - s[0];
      if (s[0] > (long long) d * (n - k + 1)){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}