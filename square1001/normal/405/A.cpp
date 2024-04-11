#include <bits/stdc++.h>
using namespace std;
int n, a[109], b[109];
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 1; i <= 100; i++) {
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(a[j] >= i) cnt++;
    }
    for(int j = n - cnt; j < n; j++) b[j]++;
  }
  for(int i = 0; i < n; i++) {
    if(i) cout << ' ';
    cout << b[i];
  }
  return 0;
}