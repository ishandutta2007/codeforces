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
    int A = 0;
    int B = 0;
    for (int j = 0; j < n; j++){
      if (j % 2 == 0 && a[j] % 2 == 1){
        A++;
      }
      if (j % 2 == 1 && a[j] % 2 == 0){
        B++;
      }
    }
    if (A != B){
      cout << -1 << endl;
    } else {
      cout << A << endl;
    }
  }
}