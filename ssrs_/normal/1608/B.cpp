#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) >= 2 || a + b > n - 2){
      cout << -1 << endl;
    } else {
      vector<int> p(n, -1);
      if (a == b){
        for (int j = 0; j <= a; j++){
          p[j * 2] = j;
        }
        int c = a + 1;
        for (int j = 0; j < n; j++){
          if (p[j] == -1){
            p[j] = c;
            c++;
          }
        }
      } else {
        int m = max(a, b);
        for (int j = 0; j < m; j++){
          p[j * 2 + 1] = n - 1 - j;
        }
        int c = n - 1 - m;
        for (int j = 0; j < n; j++){
          if (p[j] == -1){
            p[j] = c;
            c--;
          }
        }
        if (a < b){
          for (int j = 0; j < n; j++){
            p[j] = n - 1 - p[j];
          }
        }
      }
      for (int j = 0; j < n; j++){
        cout << p[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}