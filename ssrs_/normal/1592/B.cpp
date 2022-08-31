#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> a2 = a;
    sort(a2.begin(), a2.end());
    bool ok = true;
    for (int j = n - x; j < x; j++){
      if (a[j] != a2[j]){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}