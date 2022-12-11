#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

string ToLower(string x) {
  for (char& c : x)
    c = tolower(c);
  return x;
}

map<string, string> g;

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string x, y;
    cin >> x >> y >> y;
    x = ToLower(x);
    y = ToLower(y);
    g[x] = y;
  }
  int mx = 0;
  for (auto item : g) {
    string name = item.first;
    int len = 1;
    while (g.count(name)) {
      name = g[name];
      len++;
    }
    mx = max(mx, len);
  }
  cout << mx << endl;
#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}