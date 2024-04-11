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
    int ans = 0;
    for (int j = 0; j < n - 1; j++){
      int A = min(a[j], a[j + 1]);
      int B = max(a[j], a[j + 1]);
      while (A * 2 < B){
        A *= 2;
        ans++;
      }
    }
    cout << ans << endl;
  }
}