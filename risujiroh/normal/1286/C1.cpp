#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<string> ms;
  cout << "? 1 " << n << endl;
  for (int _ = n * (n + 1) / 2; _--; ) {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    ms.insert(s);
  }
  if (n == 1) {
    cout << "! " << *begin(ms) << endl;
    return 0;
  }
  cout << "? 2 " << n << endl;
  for (int _ = n * (n - 1) / 2; _--; ) {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    ms.erase(ms.find(s));
  }
  vector<string> v(n + 1);
  for (auto e : ms) {
    v[e.size()] = e;
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) {
    multiset<char> msc(begin(v[i + 1]), end(v[i + 1]));
    for (auto e : v[i]) {
      msc.erase(msc.find(e));
    }
    cout << *begin(msc);
  }
  cout << endl;
}