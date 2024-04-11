#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> h(n * 2);
    for (int j = 0; j < n * 2; j++){
      cin >> h[j];
    }
    sort(h.begin(), h.end());
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (h[n + j] < h[j] + x){
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