#include <bits/stdc++.h>
using namespace std;

bool D = false;
vector<int> ddd;

const int INF = (int)1e9 + 41;

void init() {
  for (int i = 0; i < 100000; i++)
   ddd.push_back(rand() % 1000);
}

int query(int x) {
  if (D) return ddd[x - 1];
  cout << "? " << x << endl;
  int val;
  cin >> val;
  return val;
}

void solve(int n = -1) {
  if (n == -1) cin >> n;
  if (n == 1) { cout << "! 1" << endl; return; }
  int L = 0;
  int R = n + 1;
  int M = n / 2;
  int vl = INF, vr = INF, vm = query(M);

  while (R - L > 2) {
    if (R - M > M - L) {
      int t = (M + R) / 2;
      int vt = query(t);
      if (vt > vm) {
        R = t; vr = vt;
      } else {
        L = M; vl = vm;
        M = t; vm = vt;
      }
    } else {
      int t = (L + M) / 2;
      int vt = query(t);
      if (vt > vm) {
        L = t; vl = vt;
      } else {
        R = M; vr = vm;
        M = t; vm = vt;
      }
    }
    // cout << L << " " << M << " " << R << endl;
    // cout << vl << " " << vm << " " << vr << endl;
    // cout << "---------" << endl;
  }

  if (D) {    
    cout << (M < 2 ? INF : ddd[M - 2]) << " " << ddd[M - 1] << " " << ddd[M] << endl;
  } else {
    cout << "! " << M << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  init();
  D = true;
  solve(100);
#else
  solve();
#endif  
}