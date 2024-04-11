#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    if (k * 2 >= n){
      cout << -1 << endl;
    } else {
      vector<int> p(n);
      for (int i = 0; i <= k * 2; i++){
        if (i % 2 == 0){
          p[i] = i / 2 + 1;
        } else {
          p[i] = n - i / 2;
        }
      }
      for (int i = k * 2 + 1; i < n; i++){
        p[i] = k + (i - k * 2) + 1;
      }
      for (int i = 0; i < n; i++){
        cout << p[i];
        if (i < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}