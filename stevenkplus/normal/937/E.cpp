#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

#define repi(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
vector<int> ans;

const int MAXN = 2222;
char a[MAXN], b[MAXN];

void p(int x) {
  if (x > 0) ans.push_back(x);
}

bool go() {
  int n;
  cin >> n;
  cin >> a;
  cin >> b;

  for(int i = 0; i < n; ++i) {
    int j = -1;
    for(j = n - 1 - i; j >= 0; --j) {
      if (a[j] == b[i]) {
        break;
      }
    }
    if (j == -1) return false;

    reverse(a, a + j);
    reverse(a + j, a + n - i);
    reverse(a + j, a + n - i - 1);

    reverse(a + n - i, a + n);
    reverse(a + n - i - 1, a + n);
    p(n - 1 - j);
    p(1);
    p(n);
  }

  return true;
}

int main() {
  if (go()) {
    cout << ans.size() << "\n";
    repi(i, ans) {
      printf("%d ", *i);
    }
    printf("\n");
  } else {
    cout << "-1\n";
  }
}