#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    sort(s.begin(), s.end());
    int ans = INF;
    for (int j = 0; j < n - 1; j++){
      ans = min(ans, s[j + 1] - s[j]);
    }
    cout << ans << endl;
  }
}