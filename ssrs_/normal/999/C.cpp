#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (int i = 0; i < n; i++){
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++){
    int d = min(k, cnt[i]);
    cnt[i] -= d;
    k -= d;
  }
  string t;
  for (int i = n - 1; i >= 0; i--){
    if (cnt[s[i] - 'a'] > 0){
      t += s[i];
      cnt[s[i] - 'a']--;
    }
  }
  reverse(t.begin(), t.end());
  cout << t << endl;
}