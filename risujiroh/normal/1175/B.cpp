#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr lint inf = 1LL << 32;

lint digits(auto& i) {
  lint res = 0;
  while (isdigit(*i)) res = 10 * res + *i++ - '0';
  return res;
}
lint expr(auto& i);
lint num(auto& i) {
  switch (*i) {
    case '+': return num(++i);
    case '-': return -num(++i);
    case '(': {
      lint res = expr(++i);
      return ++i, res;
    }
    default: return digits(i);
  }
}
lint term(auto& i) {
  lint res = num(i);
  while (true) switch (*i) {
    case '*': {
      res *= num(++i);
      if (res >= inf) {
        cout << "OVERFLOW!!!" << '\n';
        exit(0);
      }
      break;
    }
    case '/': res /= num(++i); break;
    default: return res;
  }
}
lint expr(auto& i) {
  lint res = term(i);
  while (true) switch (*i) {
    case '+': {
      res += term(++i);
      if (res >= inf) {
        cout << "OVERFLOW!!!" << '\n';
        exit(0);
      }
      break;
    }
    case '-': res -= term(++i); break;
    default: return res;
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int l; cin >> l;
  string s;
  while (l--) {
    string c; cin >> c;
    if (c == "for") {
      int n; cin >> n;
      s += '+' + to_string(n) + "*(0";
    } else if (c == "end") {
      s += ')';
    } else {
      s += "+1";
    }
  }
  auto i = begin(s);
  cout << expr(i) << '\n';
}