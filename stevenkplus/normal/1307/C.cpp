#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  string s;
  cin >> s;
  map<char, ll> cnt;
  map<string, ll> cnts;
  for(int i = 0; i < s.size(); ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      string k = "";
      k += c;
      k += s[i];
      cnts[k] += cnt[c];
    }
    ++cnt[s[i]];
  }
  ll ans = 0;
  for (auto p: cnts) {
    ans = max(ans, p.second);
  }
  for (auto p: cnt) {
    ans = max(ans, p.second);
  }
  cout << ans << "\n";
}