#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
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
    sort(a.begin(), a.end());
    int odd = 0;
    int even = 0;
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 1){
        odd++;
      } else {
        even++;
      }
    }
    if (odd % 2 == 0 && even % 2 == 0){
      cout << "YES" << endl;
    } else {
      bool ok = false;
      for (int j = 0; j < n - 1; j++){
        if (a[j + 1] - a[j] == 1){
          ok = true;
        }
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}