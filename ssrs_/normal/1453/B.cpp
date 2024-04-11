#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long sum = 0;
    for (int j = 0; j < n - 1; j++){
      sum += abs(a[j + 1] - a[j]);
    }
    long long ans = sum;
    ans = min(ans, sum - abs(a[1] - a[0]));
    ans = min(ans, sum - abs(a[n - 1] - a[n - 2]));
    for (int j = 1; j < n - 1; j++){
      ans = min(ans, sum - abs(a[j] - a[j - 1]) - abs(a[j + 1] - a[j]) + abs(a[j + 1] - a[j - 1]));
    }
    cout << ans << endl;
  }
}