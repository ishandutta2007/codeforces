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
      a[j]--;
    }
    int c = 1;
    vector<int> h(n);
    h[0] = 0;
    for (int j = 0; j < n; j++){
      a[j] = -1;
      while (c < n){
        if (a[j] < a[c]){
          h[c] = h[j] + 1;
          a[j] = a[c];
          c++;
        } else {
          break;
        }
      }
      if (j < n - 1 && c == j + 1){
        h[c] = h[j] + 1;
        c++;
      }
    }
    cout << h[n - 1] << endl;
  }
}