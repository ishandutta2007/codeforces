#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;
  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < n; i++){
    if (s[i] == t[i]){
      cnt[i + 1] = cnt[i];
    } else if (s[i] == '1'){
      cnt[i + 1] = cnt[i] + 1;
    } else {
      cnt[i + 1] = cnt[i] - 1;
    }
  }
  if (cnt[n] != 0){
    cout << -1 << endl;
  } else {
    int ans = 0;
    set<int> st;
    for (int i = 0; i <= n; i++){
      st.insert(cnt[i]);
      ans = max(ans, cnt[i] - *(st.begin()));
      ans = max(ans, *prev(st.end()) - cnt[i]);
    }
    cout << ans << endl;
  }
}