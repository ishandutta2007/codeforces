#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int A = 26;

struct palindrome_tree {
  int anc[N][A];
  int son[N][A];
  int fail[N];
  int cnt[N];
  int num[N];
  int len[N];
  int s[N];
  int last;
  int n;
  int p;

  int newnode(int l) {
    memset(son[p], 0, sizeof son[p]);
    cnt[p] = 0;
    num[p] = 0;
    len[p] = l;
    return p++;
  }

  void init() {
    p = 0;
    newnode(0);
    newnode(-1);
    last = 0;
    n = 0;
    s[n] = -1;
    fail[0] = 1;
  }

  int get_fail(int x) {
    while (s[n - len[x] - 1] != s[n]) {
      x = fail[x];
    }
    return x;
  }

  void add(int c) {
    c -= 'a';
    s[++n] = c;
    int cur = get_fail(last);
    if (!son[cur][c]) {
      int now = newnode(len[cur] + 2);
      fail[now] = son[get_fail(fail[cur])][c];
      son[cur][c] = now;
      num[now] = num[fail[now]] + 1;
    }
    last = son[cur][c];
    cnt[last]++;
  }

  void count() {
    for (int i = 0; i < p; ++i) {
      anc[i][0] = fail[i];
    }
    for (int j = 1; j < A; ++j) {
      for (int i = 0; i < p; ++i) {
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
      }
    }
  }

  int get(int v, int w) {
    if (len[v] <= w) {
      return len[v];
    }
    for (int i = A - 1; ~i; --i) {
      if (len[anc[v][i]] > w) {
        v = anc[v][i];
      }
    }
    return max(len[fail[v]], 0);
  }
} pt;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n);
    string ans;
    for (int rep = 0; rep < 2; ++rep) {
      pt.init();
      for (int i = 0; i < n; ++i) {
        pt.add(s[i]);
        p[i] = pt.last;
      }
      pt.count();
      pair<int, int> res(-1, -1);
      for (int len = 0; len * 2 <= n; ++len) {
        res = max(res, make_pair(len * 2 + pt.get(p[n - len - 1], n - len * 2), len));
        if (s[len] != s[n - len - 1]) {
          break;
        }
      }
      if ((int) ans.size() < res.first) {
        ans = s.substr(0, res.second) + s.substr(n - res.first + res.second, res.first - res.second);
      }
      reverse(s.begin(), s.end());
    }
    cout << ans << "\n";
  }
  return 0;
}