#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

map<int, int> s;

int find(int x) {
  auto it = s.upper_bound(x);
  if (it == s.begin()) return -1;
  --it;
  return it->first;
}

int main() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int v = find(x);
    if (v == -1 || v <= x - k) {
      if (v != -1) {
        v = s[v] + 1;
      } else {
        v = 0;
      }
      v = max(v, x - k + 1);
    }
    s[v] = max(s[v], x);
    cout << v << " ";
  }
  cout << "\n";
}