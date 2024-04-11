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
    sort(a.begin(), a.end());
    if (a[0] < 0){
      cout << "NO" << endl;
    } else {
      int k = a[n - 1] + 1;
      cout << "YES" << endl;
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << j;
        if (j < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}