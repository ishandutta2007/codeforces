#include <bits/stdc++.h>
using namespace std;

string s;
bool go() {
  cin >> s;

  char prv = 0;
  int as = 0;
  int bs = 0;
  int cs = 0;

  for(int i = 0; i < s.size(); i++) {
    if (s[i] < prv) {
      return false;
    }
    prv = s[i];
    if (s[i] == 'a') {
      as++;
    } else if (s[i] == 'b') {
      bs++;
    } else {
      cs++;
    }
  }
  if (as > 0 && bs > 0) {
    return as == cs || bs == cs;
  }
  return false;
}

int main() {
  if (go()) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}