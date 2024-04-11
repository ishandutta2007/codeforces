#include <iostream>
#include <iomanip>
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
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    multiset<int> bb;
    for (int i = 0; i < n; i++) {
      cin >> B[i];
      bb.insert(B[i]);
    }
    bool can = true;
    sort(all(A));
    for (auto x : A) {
      if (bb.find(x) != bb.end()) {
        bb.erase(bb.find(x));
      } else if (bb.find(x + 1) != bb.end()) {
        bb.erase(bb.find(x + 1));
      } else {
        can = false;
      }
    }
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}