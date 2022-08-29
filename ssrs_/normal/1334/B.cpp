#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j] -= x;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long S = 0;
    int ans = -1;
    for (int j = 0; j < n; j++){
      S += a[j];
      if (S < 0){
        ans = j;
        break;
      }
    }
    if (ans == -1){
      cout << n << endl;
    } else {
      cout << ans << endl;
    }
  }
}