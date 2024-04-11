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
      a[j]--;
    }
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]] = j;
    }
    int ans = min({max(p[0], p[n - 1]) + 1, max(n - p[0], n - p[n - 1]), p[0] + (n - p[n - 1]) + 1, p[n - 1] + (n - p[0]) + 1});
    cout << ans << endl;
  }
}