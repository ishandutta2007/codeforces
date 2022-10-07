#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> segments;


int n, m;

bool works(int rot) {
  vector<pii> segments2;
  for (auto p: segments) {
    int a = (p.first + rot) % n;
    int b = (p.second + rot) % n;
    if (a > b) swap(a, b);
    segments2.push_back(pii(a, b));
  }
  sort(segments2.begin(), segments2.end());
  return segments == segments2;
}

bool go() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;

  for(int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x %= n;
    y %= n;
    if (x > y) swap(x, y);
    segments.push_back(pii(x, y));
  }
  sort(segments.begin(), segments.end());

  for(int i = 2; i <= n; ++i) {
    if (n % i == 0) {
      bool prime = true;
      for(int j = 2; j < 100 && j < i; ++j) {
        if (i % j == 0) {
          prime = false;
          break;
        }
      }
      if (prime && works(n / i)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  if (go()) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}