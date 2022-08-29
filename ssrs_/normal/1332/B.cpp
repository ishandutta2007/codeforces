#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if (b == 0){
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main(){
  int t;
  cin >> t;
  vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> c(n, -1);
    int m = 1;
    for (int j = 0; j < 11; j++){
      bool flg = false;
      for (int k = 0; k < n; k++){
        if (a[k] % p[j] == 0 && c[k] == -1){
          c[k] = m;
          flg = true;
        }
      }
      if (flg){
        m++;
      }
    }
    m--;
    cout << m << endl;
    for (int j = 0; j < n; j++){
      cout << c[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}