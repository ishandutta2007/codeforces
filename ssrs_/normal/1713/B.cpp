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
    int mx = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, a[j]);
    }
    long long sum = a[0];
    for (int j = 0; j < n - 1; j++){
      sum += max(a[j + 1] - a[j], 0);
    }
    if (mx == sum){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}