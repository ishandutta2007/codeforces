#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  {
    string foo;
    getline(cin, foo);
    stringstream ss;
    ss << foo;
    ss >> n;
  }
  set<string> reserved;
  {
    string foo;
    getline(cin, foo);
    stringstream ss;
    ss << foo;
    for (int i = 0; i < n; ++i) {
      string bar;
      ss >> bar;
      reserved.insert(bar);
    }
  }
  int m;
  {
    string foo;
    getline(cin, foo);
    stringstream ss;
    ss << foo;
    ss >> m;
  }
  vector<string> tokens;
  auto parse_reserved = [&](string s, int start) {
    int result = 0;
    string current;
    for (int i = start; i < start + MAX && i < s.length() && s[i] != '#'; ++i) {
      current += s[i];
      if (reserved.find(current) != reserved.end()) {
        result = i - start + 1;
      }
    }
    return result;
  };
  auto parse_number = [&](string s, int start) {
    int result = 0;
    while (start + result < s.length() && isdigit(s[start + result])) {
      ++result;
    }
    return result;
  };
  auto parse_word = [&](string s, int start) {
    if (isdigit(s[start])) {
      return 0;
    }
    int result = 0;
    auto is_valid = [&](char c) {
      return isdigit(c) || isalpha(c) || c == '_' || c == '$';
    };
    while (start + result < s.length() && is_valid(s[start + result])) {
      ++result;
    }
    return result;
  };
  auto parse = [&](string s, int start) {
    return max(max(parse_reserved(s, start), parse_number(s, start)), parse_word(s, start));
  };
  while (m--) {
    string foo;
    getline(cin, foo);
    for (int i = 0; i < foo.length(); ++i) {
      if (foo[i] == ' ') {
        continue;
      }
      if (foo[i] == '#') {
        break;
      }
      int length = parse(foo, i);
      tokens.push_back(foo.substr(i, length));
      i += length - 1;
    }
  }
  map<string, string> changed;
  string last = "";
  auto find_next = [&]() {
    do {
      int i = last.length() - 1;
      while (~i && last[i] == 'z') {
        --i;
      }
      if (~i) {
        ++last[i++];
        while (i < last.length()) {
          last[i++] = 'a';
        }
      } else {
        last = string(last.length() + 1, 'a');
      }
    } while (reserved.find(last) != reserved.end());
  };
  for (auto &s : tokens) {
    if (reserved.find(s) == reserved.end() && !isdigit(s[0])) {
      if (changed.find(s) == changed.end()) {
        find_next();
        changed[s] = last;
      }
      s = changed[s];
    }
  }
  int p = tokens.size();
  for (int i = 0; i < tokens.size(); ++i) {
    string foo = tokens[i];
    for (int j = i + 1; j < tokens.size(); ++j) {
      foo += tokens[j];
      if (parse(foo, 0) != tokens[i].length()) {
        p = min(p, j - 1);
        break;
      }
      if (foo.length() > MAX) {
        break;
      }
    }
    cout << tokens[i];
    if (i == p) {
      cout << " ";
      p = tokens.size();
    }
  }
  cout << endl;
  return 0;
}