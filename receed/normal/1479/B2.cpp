#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 100002;
int dp[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
    cin >> a[i];
  a.resize(unique(all(a)) - a.begin());
  dp[0] = 1;
  int cm = 0;
  rep(i, n + 1)
    dp[i] = -n;
  for (int i = 1; i < a.size(); i++) {
    dp[a[i - 1]] = max(dp[a[i - 1]], max(cm, dp[a[i]] + 1));
    cm = max(cm, dp[a[i - 1]]);
  }
  cout << a.size() - cm;
}