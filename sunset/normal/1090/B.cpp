#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  vector<string> text;
  while (cin >> s) {
    if (s == "\\begin{thebibliography}{99}") {
      break;
    }
    if (s[0] == '\\') {
      string name;
      for (int i = 6; i < s.length(); ++i) {
        if (s[i] == '}') {
          break;
        } else {
          name += s[i];
        }
      }
      text.push_back(name);
    }
  }
  map<string, int> index;
  vector<string> reference;
  vector<string> after;
  while (cin >> s) {
    if (s == "\\end{thebibliography}") {
      break;
    }
    if (s[0] == '\\') {
      string name;
      for (int i = 9; i < s.length(); ++i) {
        if (s[i] == '}') {
          break;
        } else {
          name += s[i];
        }
      }
      index[name] = reference.size();
      reference.push_back(name);
      after.push_back(s);
    } else {
      after.back() += " " + s;
    }
  }
  if (text == reference) {
    puts("Correct");
  } else {
    puts("Incorrect");
    cout << "\\begin{thebibliography}{99}" << endl;
    for (auto s : text) {
      cout << after[index[s]] << endl;
    }
    cout << "\\end{thebibliography}" << endl;
  }
  return 0;
}