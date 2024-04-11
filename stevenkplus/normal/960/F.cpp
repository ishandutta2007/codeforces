#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

typedef pair<int, int> pii;

map<int, int> Q[MAXN]; // map<key, val>
map<int, int>::iterator it, j;

// query for max(v | k >= key)
int query(int idx, int key) {
  map<int, int> &mp = Q[idx];
  map<int, int>::iterator it = mp.upper_bound(key);
  if (it == mp.end()) return 0;
  return it->second;
}

// remove all (v < val and k < key)
void insert(int idx, int key, int val) {
  map<int, int> &mp = Q[idx];
  if (val <= query(idx, key - 1)) return;
  mp[key] = val;
  it = mp.find(key);
  if (it == mp.begin()) return;

  --it;
  while (it->second < val) {
    bool done = it == mp.begin();

    mp.erase(it--);

    if (done) break;
  }
}

int A[MAXN], B[MAXN], W[MAXN];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> A[i] >> B[i] >> W[i];
  }

  int res = 0;
  for(int i = m - 1; i >= 0; --i) {
    int ans = 1 + query(B[i], W[i]);
    insert(A[i], W[i], ans);
    res = max(res, ans);
  }

  cout << res << "\n";
}