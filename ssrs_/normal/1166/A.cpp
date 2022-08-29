#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<int> cnt(26, 0);
  for (int i = 0; i < n; i++){
    cnt[s[i][0] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++){
    int a = cnt[i] / 2;
    ans += a * (a - 1) / 2;
    int b = cnt[i] - a;
    ans += b * (b - 1) / 2;
  }
  cout << ans << endl;
}