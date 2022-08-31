#include <bits/stdc++.h>

using namespace std;

int query(vector<int> a) {
  if (a.empty()) {
    return 0;
  }
  cout << "? " << a.size() << "\n" << a[0] + 1;
  for (int i = 1; i < a.size(); ++i) {
    cout << " " << a[i] + 1;
  }
  cout << endl;
  int result;
  cin >> result;
  return result;
}

int degree(int x, vector<int> a) {
  int without = query(a);
  a.push_back(x);
  int with = query(a);
  return with - without;
}

int main() {
  int n;
  cin >> n;
  vector<int> depth(n, -1), parent(n, -1);
  queue<int> q;
  depth[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vector<int> now;
    for (int i = 0; i < n; ++i) {
      if (!~depth[i]) {
        now.push_back(i);
      }
    }
    int d = degree(x, now), last = -1;
    for (int i = 0; i < d; ++i) {
      int l = last + 1, r = now.size() - 2, result = now.size() - 1;
      while (l <= r) {
        int mid = l + r >> 1;
        vector<int> temp;
        for (int j = l; j <= mid; ++j) {
          temp.push_back(now[j]);
        }
        if (degree(x, temp)) {
          result = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      depth[now[result]] = depth[x] + 1;
      parent[now[result]] = x;
      q.push(now[result]);
      last = result;
    }
  }

  auto print = [&](int x, int y) {
    vector<int> left, right;
    while (x != y) {
      if (depth[x] >= depth[y]) {
        left.push_back(x);
        x = parent[x];
      } else {
        right.push_back(y);
        y = parent[y];
      }
    }
    left.push_back(x);
    reverse(right.begin(), right.end());
    for (auto x : right) {
      left.push_back(x);
    }
    cout << "N " << left.size() << "\n" << left[0] + 1;
    for (int i = 1; i < left.size(); ++i) {
      cout << " " << left[i] + 1;
    }
    cout << endl;
  };

  vector<int> odd, even;
  for (int i = 0; i < n; ++i) {
    if (depth[i] & 1) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }
  if (query(odd)) {
    for (auto x : odd) {
      vector<int> others;
      for (auto y : odd) {
        if (y != x) {
          others.push_back(y);
        }
      }
      if (degree(x, others)) {
        int l = 0, r = others.size() - 2, result = others.size() - 1;
        while (l <= r) {
          int mid = l + r >> 1;
          vector<int> temp;
          for (int j = 0; j <= mid; ++j) {
            temp.push_back(others[j]);
          }
          if (degree(x, temp)) {
            result = mid;
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
        print(x, others[result]);
        return 0;
      }
    }
  } else if (query(even)) {
    for (auto x : even) {
      vector<int> others;
      for (auto y : even) {
        if (y != x) {
          others.push_back(y);
        }
      }
      if (degree(x, others)) {
        int l = 0, r = others.size() - 2, result = others.size() - 1;
        while (l <= r) {
          int mid = l + r >> 1;
          vector<int> temp;
          for (int j = 0; j <= mid; ++j) {
            temp.push_back(others[j]);
          }
          if (degree(x, temp)) {
            result = mid;
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
        print(x, others[result]);
        return 0;
      }
    }
  } else {
    cout << "Y " << even.size() << "\n" << even[0] + 1;
    for (int i = 1; i < even.size(); ++i) {
      cout << " " << even[i] + 1;
    }
    cout << endl;
  }
  return 0;
}