#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long k, x;
  cin >> n >> k >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> b;
  for (int i = 0; i < n - 1; i++){
    if (a[i] < a[i + 1]){
      b.push_back((a[i + 1] - a[i] - 1) / x);
    } else {
      b.push_back(0);
    }
  }
  sort(b.begin(), b.end());
  int ans = n;
  for (int i = 0; i < n - 1; i++){
    if (k >= b[i]){
      k -= b[i];
      ans--;
    }
  }
  cout << ans << endl;
}