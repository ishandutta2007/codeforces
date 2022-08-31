#include <bits/stdc++.h>
using namespace std;
ostream& operator <<(ostream& os, __int128_t x){
  if (x < 0){
    os << '-';
    x = -x;
  }
  string s;
  while (x > 0){
    s.push_back('0' + x % 10);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  if (s.empty()){
    s = "0";
  }
  os << s;
  return os;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  __int128_t ans = 0;
  __int128_t sum = 0;
  map<long long, int> mp;
  for (int i = 0; i < n; i++){
    ans += (__int128_t) a[i] * i - sum;
    ans -= mp[a[i] - 1];
    ans += mp[a[i] + 1];
    sum += a[i];
    mp[a[i]]++;
  }
  cout << ans << endl;
}