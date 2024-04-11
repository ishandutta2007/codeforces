#include <bits/stdc++.h>
using namespace std;
string bit(long long a){
  string S;
  while (a > 0){
    S += (a % 2) + '0';
    a /= 2;
  }
  return S;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long d, m;
    cin >> d >> m;
    string S = bit(d);
    int N = S.size();
    long long ans = 1;
    for (int i = 0; i < N - 1; i++){
      ans = ans * ((1 << i) + 1) % m;
    }
    ans = ans * (d - (1 << (N - 1)) + 2) % m;
    ans = (ans + m - 1) % m;
    cout << ans << endl;
  }
}