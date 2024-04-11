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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    long long ans = 0;
    for (int j = 0; j < n - 1; j++){
      ans += min(abs(a[j + 1] - a[j]) + abs(b[j + 1] - b[j]), abs(a[j + 1] - b[j]) + abs(b[j + 1] - a[j]));
    }
    cout << ans << endl;
  }
}