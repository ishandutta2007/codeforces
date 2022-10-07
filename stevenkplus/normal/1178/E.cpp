#include <iostream>
#include <algorithm>
using namespace std;

string s;
int main() {
  cin >> s;
  string a, b, c;
  int i = 0, j = s.size() - 1;
  while (i <= j) {
    if (j - i <= 2) {
      b = s[i];
      break;
    } else {
      char ch = s[i];
      if (ch != s[j] && ch != s[j - 1]) {
        ch = s[i + 1];
      }
      a += ch;
      c += ch;
      i += 2;
      j -= 2;
    }
  }
  reverse(c.begin(), c.end());
  cout << a << b << c << "\n";
}