#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.begin(), P.end(), greater<pair<int, int>>());
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += P[i].first * i + 1;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++){
    cout << P[i].second + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}