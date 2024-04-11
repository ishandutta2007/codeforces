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
    vector<int> c(3, 0);
    for (int j = 0; j < n; j++){
      c[a[j] % 3]++;
    }
    int ans = 0;
    for (int j = 0; j < 10; j++){
      if (c[j % 3] > n / 3){
        int d = c[j % 3] - n / 3;
        c[j % 3] -= d;
        c[(j + 1) % 3] += d;
        ans += d;
      }
    }
    cout << ans << endl;
  }
}