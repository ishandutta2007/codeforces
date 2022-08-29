#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >>t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    if (n == 1){
      if (a[0] == 1){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (a[n - 1] - a[n - 2] >= 2){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}