#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  string t;

  cin >> s >> t;

  int lbound = -1, rbound = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      lbound = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] != t[i]) {
      rbound = i;
      break;
    }
  }

  if (rbound == lbound) {
    cout << 2 << endl;
    return 0;
  }

  bool ok1 = true, ok2 = true;
  for (int i = lbound + 1; i <= rbound; ++i) {
    if (s[i] != t[i - 1]) {
      ok1 = false;
      break;
    }
  }
  for (int i = lbound; i < rbound; ++i) {
    if (s[i] != t[i + 1]) {
      ok2 = false;
      break;
    }
  }
  if (ok1 && ok2) {
    cout << 2 << endl;
    return 0;
  }
  if (ok1 || ok2) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}