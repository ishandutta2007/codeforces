#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;
int ar[MAXN];
int res[MAXN];
pii s[MAXN];

int main() {
  int N;
  cin >> N;
  for (int j = 0; j < N; ++j) {
    cin >> ar[j];
    s[j] = pii(ar[j], j);
  }
  sort(s, s + N);
  for(int i = N - 1; i >= 0; --i) {
    int j = s[i].second;
    int ans = 1;
    int m = ar[j];
    for(int k = j % m; k < N; k += m) {
      if (k == j) continue;
      if (!res[k]) continue;
      if (res[k] == 1) {
        ans = 2;
        break;
      }
    }

    res[j] = ans;
  }
  for(int i = 0; i < N; ++i) {
    if (res[i] == 1) {
      cout << "B";
    } else {
      cout << "A";
    }
  }
  cout << "\n";
}