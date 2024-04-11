#include <bits/stdc++.h>
using namespace std;
long long INF = (long long) 1 << 50;
string bit(long long a){
  if (a == 0){
    return "0";
  } else {
    string ans = "";
    while (a > 0){
      ans += a % 2 + '0';
      a /= 2;
    }
    return ans;
  }
}
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
    int m = 0;
    for (int j = 0; j < n - 1; j++){
      if (a[j] > a[j + 1]){
        long long d = a[j] - a[j + 1];
        m = max(m, (int) bit(d).size());
        a[j + 1] = a[j];
      }
    }
    cout << m << endl;
  }
}