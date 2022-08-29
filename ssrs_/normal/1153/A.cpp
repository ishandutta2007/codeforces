#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, t;
  cin >> n >> t;
  vector<int> s(n), d(n);
  for (int i = 0; i < n; i++){
    cin >> s[i] >> d[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    a[i] = s[i];
    if (a[i] < t){
      a[i] += (t - s[i] + d[i] - 1) / d[i] * d[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (a[i] < a[ans]){
      ans = i;
    }
  }
  cout << ans + 1 << endl;
}