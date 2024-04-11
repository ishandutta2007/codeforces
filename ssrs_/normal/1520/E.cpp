#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '*'){
        a.push_back(j - cnt);
        cnt++;
      }
    }
    sort(a.begin(), a.end());
    if (a.empty()){
      cout << 0 << "\n";
    } else {
      int m = a[cnt / 2];
      long long ans = 0;
      for (int j = 0; j < cnt; j++){
        ans += abs(a[j] - m);
      }
      cout << ans << "\n";
    }
  }
}