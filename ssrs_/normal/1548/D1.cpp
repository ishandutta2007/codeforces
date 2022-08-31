#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if (b == 0){
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> cnt(4, 0);
  for (int i = 0; i < n; i++){
    x[i] = x[i] / 2 % 2;
    y[i] = y[i] / 2 % 2;
    cnt[x[i] * 2 + y[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      if (i != j){
        ans += (long long) cnt[i] * (cnt[i] - 1) / 2 * cnt[j];
      }
    }
    ans += (long long) cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
  }
  cout << ans << endl;
}