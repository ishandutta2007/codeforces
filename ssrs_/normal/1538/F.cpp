#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    string S = to_string(l), T = to_string(r);
    while (S.size() < 10){
      S = "0" + S;
    }
    while (T.size() < 10){
      T = "0" + T;
    }
    long long ans = 0;
    for (int j = 1; j <= 10; j++){
      long long x = stoll(S.substr(0, j));
      long long y = stoll(T.substr(0, j));
      ans += y - x;
    }
    cout << ans << endl;
  }
}