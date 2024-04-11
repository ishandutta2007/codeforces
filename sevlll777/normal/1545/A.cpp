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
#include <complex>
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
const int N = 100500;
int pos[N], cnt[N], posb[N];

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    pos[A[i]] = 0;
    posb[A[i]] = 0;
    cnt[A[i]] = 0;
  }
  for (int i = 0; i < n; i++) {
    pos[A[i]] += i % 2;
    cnt[A[i]]++;
  }
  vector<int> B = A;
  sort(all(B));
  for (int i = 0; i < n; i++) {
    posb[B[i]] += i % 2;
  }
  for (auto x : A) {
    if (posb[x] != pos[x]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}