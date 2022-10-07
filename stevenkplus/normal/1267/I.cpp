#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define x first
#define y second

int q(int a, int b) {
  cout << "? " << a << " " << b << endl;
  string ch;
  cin >> ch;
  if (ch == ">") {
    return -1;
  }
  return 1;
}

vector<piii> v;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    v.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      int a = i;
      int b = i + n;
      if (q(a, b) == 1) {
        swap(a, b);
      }
      v.push_back(piii(a, pii(b, 0)));
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if (i == j) continue;
        int val = q(v[i].y.x, v[j].y.x);
        if (val == -1) {
          ++v[i].y.y;
        }
      }
    }
    for(int i = 0; i < n; ++i) {
      v[i] = piii(-v[i].y.y, pii(v[i].x, v[i].y.x));
    }
    sort(v.begin(), v.end());
    int val = q(v[1].y.x, v[2].y.x);
    int a = v[0].y.x;
    int b = val == -1 ? v[1].y.x : v[2].y.x;
    for(int i = 1; i <= 2 * n; ++i) {
      if (i == a || i == b) continue;
      for(int j = i + 1; j <= 2 * n; ++j) {
        if (j == a || j == b) continue;
        q(i, j);
      }
    }
    cout << "!" << endl;
  }
  return 0;
}