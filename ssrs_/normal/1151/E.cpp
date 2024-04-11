#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++){
    long long A = a[i];
    long long B = a[i + 1];
    if (A < B){
      ans += A * (B - A);
    }
    if (A > B){
      ans += (n - A + 1) * (A - B);
    }
  }
  cout << ans << endl;
}