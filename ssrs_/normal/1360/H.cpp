#include <bits/stdc++.h>
using namespace std;
long long ll(string s){
  long long ans = 0;
  int N = s.size();
  for (int i = 0; i < N; i++){
    if (s[i] == '1'){
      ans += ((long long) 1) << (N - i - 1);
    }
  }
  return ans;
}
string st(long long a, int m){
  string ans;
  for (int i = m - 1; i >= 0; i--){
    if ((a >> i) & 1){
      ans += '1';
    } else {
      ans += '0';
    }
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      string s;
      cin >> s;
      a[j] = ll(s);
    }
    sort(a.begin(), a.end());
    long long tv = ((long long) 1) << m;
    long long k = tv - n;
    long long fv = -1;
    while (tv - fv > 1){
      long long mv = (tv + fv) / 2;
      long long cnt = mv - (lower_bound(a.begin(), a.end(), mv) - a.begin());
      if (cnt >= (k - 1) / 2){
        tv = mv;
      } else {
        fv = mv;
      }
    }
    while (upper_bound(a.begin(), a.end(), tv) != lower_bound(a.begin(), a.end(), tv)){
      tv++;
    }
    cout << st(tv, m) << endl;
  }
}