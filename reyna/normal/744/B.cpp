// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 1e3 + 3, mod = (int) 0;
int cnt, n, w[N][N], res[N];
void do_ask(vector<int> a) {
  if ((int) a.size() == 0) return;
  sort(a.begin(), a.end());
  cout << (int) a.size() << endl;
  for (int j : a) {
    cout << j + 1 << ' ';
  }
  cout << endl;
  for (int j = 0; j < n; ++j) {
    cin >> w[cnt][j];
  }
  cnt++;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  memset(w, 63, sizeof w);
  for (int j = 0; j < 10; ++j) {
    for (int x = 0; x < 2; ++x) {
      vector<int> ask;
      for (int i = 0; i < n; ++i) {
        if ((i >> j & 1) == x) {
          ask.push_back(i);
        }
      }
      if ((int) ask.size() != n)
        do_ask(ask);
    }
  }
  memset(res, 63, sizeof res);
  for (int j = 0; j < n; ++j) {
    for (int x = 0; x < 10; ++x) {
      int ind = x * 2 + ((j >> x & 1) ^ 1);
      res[j] = min(res[j], w[ind][j]);
    }
  }
  cout << -1 << endl;
  for (int j = 0; j < n; ++j) {
    cout << res[j] << ' ';
  }
  cout << endl;
}