#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x;
    cin >> x;
    string s;
    cin >> s;
    long long ans = s.size();
    bool big = false;
    for (int j = 1; j <= x; j++){
      long long c = (ans - j + MOD) % MOD;
      ans += c * (s[j - 1] - '1');
      ans %= MOD;
      if (s[j - 1] > '1' && s.size() < x){
        string C = s.substr(j);
        if (s[j - 1] == '2'){
          s += C;
        }
        if (s[j - 1] == '3'){
          s += C;
          s += C;
        }
      }
    }
    cout << ans << endl;
  }
}