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
    int x = 0, y = 0;
    for (int j = 1; j < n; j++){
      if (a[j] < a[x]){
        x = j;
      }
      if (a[j] > a[y]){
        y = j;
      }
    }
    cout << x + 1 << ' ' << y + 1 << endl;
  }
}