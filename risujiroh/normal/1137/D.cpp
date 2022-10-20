#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  auto read = []() -> V<string> {
    int k; cin >> k;
    V<string> s(k); for (auto&& e : s) cin >> e;
    return s;
  };
  while (true) {
    cout << "next 0 1" << endl;
    read();
    cout << "next 0" << endl;
    if (read().size() == 2) break;
  }
  while (true) {
    cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    if (read().size() == 1) {
      cout << "done" << endl;
      return 0;
    }
  }
}