#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
  if (b == 0){
    return a;
  } else {
    return gcd(b, a % b);
  }
}
struct swag{
  stack<pair<long long, long long>> fr, bk;
  swag(){
  }
  void push(long long x){
    if (fr.empty()){
      fr.push(make_pair(x, x));
    } else {
      fr.push(make_pair(x, gcd(fr.top().second, x)));
    }
  }
  void pop(){
    if (bk.empty()){
      while (!fr.empty()){
        long long x = fr.top().first;
        fr.pop();
        if (bk.empty()){
          bk.push(make_pair(x, x));
        } else {
          bk.push(make_pair(x, gcd(bk.top().second, x)));
        }
      }
    }
    bk.pop();
  }
  long long get(){
    long long ans = 0;
    if (!fr.empty()){
      ans = gcd(ans, fr.top().second);
    }
    if (!bk.empty()){
      ans = gcd(ans, bk.top().second);
    }
    return ans;
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> d(n - 1);
    for (int j = 0; j < n - 1; j++){
      d[j] = abs(a[j + 1] - a[j]);
    }
    int ans = 1;
    swag S;
    int R = 0;
    for (int L = 0; L < n - 1; L++){
      while (R < n - 1){
        if (gcd(S.get(), d[R]) > 1){
          S.push(d[R]);
          R++;
        } else {
          break;
        }
      }
      ans = max(ans, R - L + 1);
      if (R == L){
        R++;
      } else {
        S.pop();
      }
    }
    cout << ans << "\n";
  }
}