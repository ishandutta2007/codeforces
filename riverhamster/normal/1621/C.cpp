#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)


const int N = 10005;

int p[N];
bool vis[N];

int main() {
// #ifdef LOCAL
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    fill(vis + 1, vis + 1 + n, 0);
    fill(p + 1, p + 1 + n, 0);
    FOR (i, 1, n) {
      if (p[i]) continue;
      vector<int> v;
      int q;
      do {
        cout << "? " << i << endl;
        cin >> q;
        if (vis[q]) break;
        vis[q] = true;
        v.push_back(q);
      } while (true);
      rotate(v.begin(), find(all(v), i), v.end());
      int pos = i;
      for (int i = 1, li = v.size(); i < li; ++i) {
        p[pos] = v[i];
        pos = v[i];
      }
      p[pos] = i;
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i)
      cout << p[i] << ' ';
    cout << endl;
  }
  return 0;
}