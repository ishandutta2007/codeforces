// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  string s;
  cin >> s;
  set<char> k;
  int len = 0;
  for (char c: s) {
    if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
      k.insert(c);
      ++len;
    } else {
      k.clear();
      len = 0;
    }
    if (len >= 3 && k.size() > 1) {
      cout << " ";
      k.clear();
      k.insert(c);
      len = 1;
    }
    cout << c;
  }
  cout << "\n";
}