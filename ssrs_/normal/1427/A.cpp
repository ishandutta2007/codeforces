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
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    if (sum == 0){
      cout << "NO" << endl;
    }
    if (sum > 0){
      cout << "YES" << endl;
      sort(a.rbegin(), a.rend());
      for (int j = 0; j < n; j++){
        cout << a[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
    if (sum < 0){
      cout << "YES" << endl;
      sort(a.begin(), a.end());
      for (int j = 0; j < n; j++){
        cout << a[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}