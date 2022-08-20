#include <bits/stdc++.h>

using namespace std;

const int A = 26;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> c(A);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      c[s[i] - 'a']++;
    }
    if (*max_element(c.begin(), c.end()) == n) {
      cout << s << "\n";
      continue;
    }
    auto print = [&](int w) {
      cout << (char) (w + 'a');
      c[w]--;
    };
    bool single = false;
    for (int i = 0; i < A; ++i) {
      if (c[i] == 1) {
        single = true;
        print(i);
        for (int j = 0; j < A; ++j) {
          while (c[j]) {
            print(j);
          }
        }
        cout << "\n";
        break;
      }
    }
    if (single) {
      continue;
    }
    int w = 0;
    while (!c[w]) {
      ++w;
    }
    if (c[w] * 2 <= n + 2) {
      print(w);
      while (c[w]) {
        print(w);
        for (int i = w + 1; i < A; ++i) {
          if (c[i]) {
            print(i);
            break;
          }
        }
      }
      for (int i = 0; i < A; ++i) {
        while (c[i]) {
          print(i);
        }
      }
      cout << "\n";
    } else {
      int x = w + 1;
      while (!c[x]) {
        ++x;
      }
      if (c[x] + c[w] < n) {
        print(w);
        print(x);
        while (c[w]) {
          print(w);
        }
        for (int i = x + 1; i < A; ++i) {
          if (c[i]) {
            print(i);
            break;
          }
        }
        for (int i = 0; i < A; ++i) {
          while (c[i]) {
            print(i);
          }
        }
      } else {
        print(w);
        while (c[x]) {
          print(x);
        }
        while (c[w]) {
          print(w);
        }
      }
      cout << "\n";
    }
  }
  return 0;
}