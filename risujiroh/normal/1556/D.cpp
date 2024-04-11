#include <bits/stdc++.h>

using namespace std;

template <class C> constexpr int len(const C& c) { return int(c.size()); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  --k;

  vector<int> v_and(n);
  vector<int> v_or(n);
  for (int i = 0; i + 1 < n; ++i) {
    cout << "and " << i + 1 << ' ' << i + 2 << endl;
    cin >> v_and[i];
    cout << "or " << i + 1 << ' ' << i + 2 << endl;
    cin >> v_or[i];
  }
  cout << "and 1 3" << endl;
  cin >> v_and.back();
  cout << "or 1 3" << endl;
  cin >> v_or.back();

  vector<int> a(n);
  for (int s = 0; s < 30; ++s) {
    int p = -1;
    for (int i = 0; i < n - 1; ++i) {
      if ((v_and[i] >> s & 1) == (v_or[i] >> s & 1)) {
        p = i;
        break;
      }
    }

    if (~p) {
      a[p] |= v_and[p] & 1 << s;
      a[p + 1] |= v_and[p] & 1 << s;

      for (int i = p; i--;) {
        if ((v_and[i] >> s & 1) == (v_or[i] >> s & 1)) {
          a[i] |= v_and[i] & 1 << s;
        } else {
          a[i] |= ~a[i + 1] & 1 << s;
        }
      }
      for (int i = p + 2; i < n; ++i) {
        if ((v_and[i - 1] >> s & 1) == (v_or[i - 1] >> s & 1)) {
          a[i] |= v_and[i - 1] & 1 << s;
        } else {
          a[i] |= ~a[i - 1] & 1 << s;
        }
      }
    } else {
      assert((v_and.back() >> s & 1) == (v_or.back() >> s & 1));
      if (v_and.back() >> s & 1) {
        for (int i = 0; i < n; i += 2) {
          a[i] |= 1 << s;
        }
      } else {
        for (int i = 1; i < n; i += 2) {
          a[i] |= 1 << s;
        }
      }
    }
  }

  nth_element(begin(a), begin(a) + k, end(a));
  cout << "finish " << a[k] << endl;
}