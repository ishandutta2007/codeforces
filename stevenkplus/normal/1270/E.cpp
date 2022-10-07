#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 100100;
int X[MAXN], Y[MAXN];

int main() {
  int n;
  cin >> n;
  bool ok = false;
  for(int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    X[i] = x;
    Y[i] = y;
  }
  while (!ok) {
    vector<int> v;
    for(int i = 0; i < n; ++i) {
      if ((X[i] + Y[i]) % 2 == 0) {
        v.push_back(i + 1);
      }
    }
    if (v.size() != 0 && v.size() != n) {
      ok = true;
      cout << v.size() << "\n";
      for(int i: v) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      int a = (X[0] + Y[0]) % 2 == 0 ? 0 : 1;
      for(int i = 0; i < n; ++i) {
        int x = X[i];
        int y = Y[i];
        X[i] = (x + y + a) / 2;
        Y[i] = (x - y + a) / 2;
      }
    }
  }
}