// scott typing in programmer's dvorak
//
// abcdefghijklmnpoqrstuvwxyz
//

#include <iostream>
int main() {
  using namespace std;
  string a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  string t;
  for (int i = 0; i < s.length(); i++) {
    int idx = 0;
    for (int j = 0; j < a.length(); j++) {
      bool isUpper = s[i] <= 'Z';
      if (isUpper && a[j] == (s[i] + 'a' - 'A'))
        idx = j;
      if (!isUpper && a[j] == s[i]) idx = j;
    }
    if (s[i] >= '0' && s[i] <= '9') {
      t += s[i];
    } else if (s[i] <= 'Z') {
      t += char(b[idx] + ('A' - 'a'));
    } else {
      t += b[idx];
    }} cout << t << "\n";}