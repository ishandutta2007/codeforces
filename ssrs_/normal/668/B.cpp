#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  int g1 = 0, g2 = 1;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x;
      cin >> x;
      g1 += x;
      g1 = (g1 + n) % n;
      g2 += x;
      g2 = (g2 + n) % n;
    }
    if (t == 2){
      g1 ^= 1;
      g2 ^= 1;
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n / 2; i++){
    ans[(g1 + i * 2) % n] = i * 2;
    ans[(g2 + i * 2) % n] = i * 2 + 1;
  }
  for (int i = 0; i < n; i++){
    cout << ans[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}