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
    int p = 0;
    for (int j = 1; j < n; j++){
      if (a[j] < a[p]){
        p = j;
      }
    }
    cout << n - 1 << endl;
    for (int j = 0; j < n; j++){
      if (j != p){
        if ((j - p) % 2 == 0){
          cout << j + 1 << ' ' << p + 1 << ' ' << a[p] << ' ' << a[p] << endl;
        } else {
          cout << j + 1 << ' ' << p + 1 << ' ' << a[p] + 1 << ' ' << a[p] << endl;
        }
      }
    }
  }
}