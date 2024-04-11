#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long ans = INF;
  for (int i = 0; i < n; i++){
    vector<long long> b(n);
    b[i] = 0;
    long long cnt = 0;
    for (int j = i + 1; j < n; j++){
      long long q = b[j - 1] / a[j] + 1;
      cnt += q;
      b[j] = q * a[j];
    }
    for (int j = i - 1; j >= 0; j--){
      long long q = b[j + 1] / a[j] + 1;
      cnt += q;
      b[j] = q * a[j];
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}