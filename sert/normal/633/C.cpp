#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll P = 37;
const ll MD = (ll)1e9 + 9;

vector<ll> deg;

vector<ll> getHashes(const string &s) {
  vector<ll> h(s.size() + 1, 0);
  for (int i = 0; i < (int)s.length(); i++)
    h[i + 1] = (h[i] * P + s[i] - 'a' + 1) % MD;
  return h;
}

ll getRevHash(const string &s) {
  ll h = 0;
  for (int i = (int)s.length() - 1; i >= 0; i--) {
    char ch = s[i];
    if ('A' <= ch && ch <= 'Z') 
      ch = ch + 'a' - 'A';
    h = (h * P + ch - 'a' + 1) % MD;
  }
  return h;
}

ll getSegHash(const vector<ll> &hashes, int l, int r) {
  return (hashes[r] - hashes[l] * deg[r - l] + MD * MD) % MD;
}

void init() {
  deg.resize(12345);
  deg[0] = 1;
  for (int i = 1; i < (int)deg.size(); i++)
    deg[i] = deg[i - 1] * P % MD;
}

int main() {
  init();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  auto hashes = getHashes(s);

  set<int> lengths;
  map<int, map<ll, string>> mp;

  int w;
  cin >> w;

  for (int i = 0; i < w; i++) {
    string t;
    cin >> t;
    ll hsh = getRevHash(t);
    mp[t.length()][hsh] = t;    
  }

  vector<string> dp(s.length() + 1);

  for (int pos = 0; pos < (int)s.length(); pos++) {  
    if (pos > 0 && dp[pos].empty()) continue;  
    int maxLen = (int)s.length() - pos;
    for (auto &it : mp) {
      int len = it.first;
      if (len > maxLen) continue;
      ll hsh = getSegHash(hashes, pos, pos + len);

      if (it.second.count(hsh)) {
        string t = it.second[hsh];
        dp[pos + len] = t;
      }
    }
  }

  // for (int i = 0; i < (int)dp.size(); i++) {
  //   cout << (i < (int)s.length() ? s[i] : '#') << " " << dp[i] << endl;
  // }

  int pos = s.length();
  vector<string> ans;
  while (pos > 0) {
    ans.push_back(dp[pos]);
    pos -= ans.back().length();
  }

  reverse(ans.begin(), ans.end());
  for (const string &s : ans)
    cout << s << " ";
  cout << endl;

  return 0;
}