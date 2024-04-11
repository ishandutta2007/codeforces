#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
int f(int x, int n){
  int r = (x - n + INF) % 4;
  if (r == 0){
    return x + 2;
  } else if (r == 1){
    return x + 3;
  } else if (r == 2){
    return x - 1;
  } else {
    return x;
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n <= 3){
      cout << -1 << endl;
    } else {
      vector<int> a(n);
      if (n % 4 == 0){
        for (int j = 0; j < n; j++){
          a[j] = f(j, n);
        }
      } else if (n % 4 == 1){
        a[0] = 2;
        a[1] = 5;
        a[2] = 3;
        a[3] = 1;
        a[4] = 4;
        for (int j = 5; j < n; j++){
          a[j] = f(j, n);
        }
      } else if (n % 4 == 2){
        a[0] = 1;
        a[1] = 4;
        a[2] = 2;
        a[3] = 6;
        a[4] = 3;
        a[5] = 5;
        for (int j = 6; j < n; j++){
          a[j] = f(j, n);
        }
      } else {
        a[0] = 7;
        a[1] = 4;
        a[2] = 2;
        a[3] = 6;
        a[4] = 3;
        a[5] = 1;
        a[6] = 5;
        for (int j = 7; j < n; j++){
          a[j] = f(j, n);
        }
      }
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