#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(31, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= 30; j++){
      if (a[i] == (1 << j)){
        cnt[j]++;
      }
    }
  }
  for (int i = 0; i < q; i++){
    int b;
    cin >> b;
    int ans = 0;
    for (int j = 30; j >= 0; j--){
      int u = b / (1 << j);
      int add = min(u, cnt[j]);
      ans += add;
      b -= add << j;
    }
    if (b != 0){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}