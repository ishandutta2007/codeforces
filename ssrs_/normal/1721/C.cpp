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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> mn(n);
    mn[0] = b[0] - a[0];
    int p = 0;
    for (int j = 1; j < n; j++){
      if (a[j - 1] > b[j]){
        p = j;
      }
      while (b[p] < a[j]){
        p++;
      }
      mn[j] = b[p] - a[j];
    }
    vector<int> mx(n);
    mx[n - 1] = b[n - 1] - a[n - 1];
    int p2 = n - 1;
    for (int j = n - 2; j >= 0; j--){
      if (a[j + 1] > b[j]){
        p2 = j;
      }
      mx[j] = b[p2] - a[j];
    }
    for (int j = 0; j < n; j++){
      cout << mn[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
    for (int j = 0; j < n; j++){
      cout << mx[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}