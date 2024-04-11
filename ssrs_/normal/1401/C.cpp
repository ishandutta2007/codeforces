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
    int m = *min_element(a.begin(), a.end());
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (a[j] != b[j] && a[j] % m != 0){
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