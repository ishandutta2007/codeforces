#include <bits/stdc++.h>

using namespace std;

const int N = 1234;
const long long MAX = (long long) 1e18;

mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
pair<long long, long long> intervals[N];
long long m, y;
int n;

long long query(int x, long long y) {
  cout << "? " << x + 1 << " " << y << endl;
  long long p;
  cin >> p;
  return p;
}

long long binary_search(int who, long long w, long long l, long long r) {
  while (true) {
    long long m = (l + r) >> 1;
    long long v = query(who, m);
    if (v > w) {
      r = m - 1;
    } else if (v < w) {
      l = m + 1;
    } else {
      return m;
    }
  }
}

pair<vector<int>, vector<int>> split_leftmost_k(vector<int> a, int o, int k, long long l, long long r) {
  vector<int> left, middle, right;
  int p = a[mrand() % a.size()];
  long long q = binary_search(p, m / n * o, l, r);
  middle.push_back(p);
  for (auto i : a) {
    if (i != p) {
      long long v = query(i, q);
      if (v > m / n * o) {
        left.push_back(i);
      } else if (v < m / n * o) {
        right.push_back(i);
      } else {
        middle.push_back(i);
      }
    }
  }
  while ((int) left.size() < k && !middle.empty()) {
    left.push_back(middle.back());
    middle.pop_back();
  }
  if ((int) left.size() == k) {
    y = q;
    for (auto x : middle) {
      right.push_back(x);
    }
    return make_pair(left, right);
  } else if ((int) left.size() < k) {
    pair<vector<int>, vector<int>> down = split_leftmost_k(right, o, k - left.size(), l, r);
    for (auto x : left) {
      down.first.push_back(x);
    }
    return down;
  } else {
    pair<vector<int>, vector<int>> down = split_leftmost_k(left, o, k, l, r);
    for (auto x : right) {
      down.second.push_back(x);
    }
    for (auto x : middle) {
      down.second.push_back(x);
    }
    return down;
  }
}

void solve(vector<int> a, int o, long long l, long long r) {
  if ((int) a.size() == 1) {
    intervals[a.back()] = make_pair(l, r);
  } else {
    int m = a.size() / 2;
    pair<vector<int>, vector<int>> left_and_right = split_leftmost_k(a, o + m, m, l, r);
    long long y = ::y;
    solve(left_and_right.first, o, l, y);
    solve(left_and_right.second, o + m, y, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
  }
  solve(a, 0, 0, MAX);
  cout << "!" << endl;
  for (int i = 0; i < n; ++i) {
    cout << intervals[i].first << " " << intervals[i].second << endl;
  }
  return 0;
}