#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(all(A));
  int sum = 0;
  for (auto x : A) sum += x;
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> y >> x;
    if (A[0] >= y) {
      cout << max(0LL, x - (sum - A[0])) << '\n';
    } else if (A[n - 1] < y) {
      cout << y - A[n - 1] + max(0LL, x - (sum - A[n - 1])) << '\n';
    } else {
      int i = (int) (lower_bound(all(A), y) - A.begin()) - 1;
      int opt1 = (y - A[i]) + max(0LL, x - (sum - A[i]));
      int opt2 = max(0LL, x - (sum - A[i + 1]));
      cout << min(opt1, opt2) << '\n';
    }
  }

}