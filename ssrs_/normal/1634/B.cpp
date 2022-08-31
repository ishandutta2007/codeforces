#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    long long y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 1){
        cnt++;
      }
    }
    if (cnt % 2 == 0){
      if (x % 2 == y % 2){
        cout << "Alice" << endl;
      } else {
        cout << "Bob" << endl;
      }
    } else {
      if (x % 2 == y % 2){
        cout << "Bob" << endl;
      } else {
        cout << "Alice" << endl;
      }
    }
  }
}