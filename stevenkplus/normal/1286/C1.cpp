#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;

int main() {
  int n;
  cin >> n;
  cout << "? 1 " << n << endl;
  if (n > 1) {
    cout << "? 2 " << n << endl;
  }
  for (int i = 0; i < (n + 1) * n / 2; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ++mp[s];
  }
  for (int i = 0; i < (n - 1) * n / 2; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    --mp[s];
  }

  vector<string> v(n);
  for(auto p: mp) {
    cerr << p.first << " " << p.second << "\n";
    if (p.second > 0) {
      cerr << "found " << p.first << "\n";
      v[p.first.size() - 1] = p.first;
    }
  }
  string ans;
  map<char, int> prv;
  for (string s: v) {
    map<char, int> mp;
    for (char c: s) {
      ++mp[c];
    }
    for (auto p: mp) {
      if (p.second > prv[p.first]) {
        ans += p.first;
      }
    }
    prv = mp;
  }
  cout << "! " << ans << endl;
}