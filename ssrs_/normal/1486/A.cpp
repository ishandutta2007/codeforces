#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    bool ok = true;
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += h[j];
      if (sum < j * (j + 1) / 2){
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