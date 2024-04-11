#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 4 == 2){
      cout << "NO" << endl;
    } else {
      vector<long long> a(n);
      long long S = 0;
      for (int j = 0; j < n / 2; j++){
        a[j] = (j + 1) * 2;
        S += a[j];
      }
      for (int j = n / 2; j < n - 1; j++){
        a[j] = (j - n / 2) * 2 + 1;
        S -= a[j];
      }
      a[n - 1] = S;
      cout << "YES" << endl;
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