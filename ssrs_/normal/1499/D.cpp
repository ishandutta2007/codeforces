#include <bits/stdc++.h>
using namespace std;
const int MAX = 20000000;
int main(){
  vector<int> cnt(MAX + 1, 0);
  for (int i = 2; i <= MAX; i++){
    if (cnt[i] == 0){
      for (int j = i; j <= MAX; j += i){
        cnt[j]++;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int c, d, x;
    cin >> c >> d >> x;
    vector<int> f;
    for (int j = 1; j * j <= x; j++){
      if (x % j == 0){
        f.push_back(j);
        if (j * j < x){
          f.push_back(x / j);
        }
      }
    }
    long long ans = 0;
    for (int r : f){
      if ((r + d) % c == 0){
        int k = (r + d) / c;
        ans += 1 << cnt[k];
      }
    }
    cout << ans << endl;
  }
}