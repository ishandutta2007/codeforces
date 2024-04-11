// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  int n;
  cin >> n;
  int cur = 1, sum = 0;
  vector<int> v;
  while (sum + cur <= n) {
    v.push_back(cur);
    sum += cur;
    ++cur;
  }
  v[v.size() - 1] += n - sum;
  cout << v.size() << "\n";
  for (int i: v) {
    cout << i << " ";
  }
  cout << "\n";
}