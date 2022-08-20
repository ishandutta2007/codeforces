#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  map<pair<string, int>, vector<int>> group;
  for (int i = 0; i < n; ++i) {
    string foo, bar;
    cin >> foo >> bar;
    int letters = 0;
    for (auto c : bar) {
      letters |= 1 << c - 'a';
    }
    while (!foo.empty() && (letters >> foo.back() - 'a' & 1)) {
      foo.pop_back();
    }
    group[make_pair(foo, letters)].push_back(i);
  }
  printf("%d\n", group.size());
  for (auto p : group) {
    printf("%d", p.second.size());
    for (auto x : p.second) {
      printf(" %d", x + 1);
    }
    putchar(10);
  }
  return 0;
}