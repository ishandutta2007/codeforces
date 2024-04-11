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
    long long ans = 0;
    for (int j = 0; j < n; j++){
      if (a[j] == 1){
        ans++;
      }
    }
    for (int j = 0; j < n; j++){
      if (a[j] == 0){
        ans *= 2;
      }
    }
    cout << ans << endl;
  }
}