#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(20, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 20; j++){
      if ((a[i] >> j) & 1){
        cnt[j]++;
      }
    }
  }
  vector<long long> b(n, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 20; j++){
      if (i < cnt[j]){
        b[i] += (1 << j);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += b[i] * b[i];
  }
  cout << ans << endl;
}