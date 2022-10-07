#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111;

int A[MAXN], B[MAXN];
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> B[i];
    }
    sort(A, A + n);
    sort(B, B + n);
    for (int i = 0; i < n; ++i) {
      cout << A[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
      cout << B[i] << " ";
    }
    cout << "\n";
  }
}