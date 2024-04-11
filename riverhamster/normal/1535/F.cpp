#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

#define all(cont) begin(cont), end(cont)

const int N = 200005;

unordered_map<string, vector<string>> equiv;

int c[N][26];
vector<int> id[N];
int nc = 0;

int lcp[N];

void insert(const string &s, int ID) {
  int x = 0;
  for (auto p = rbegin(s); p != rend(s); ++p) {
    id[x].push_back(ID);
    if (!c[x][*p - 'a']) c[x][*p - 'a'] = ++nc;
    x = c[x][*p - 'a'];
  }
  id[x].push_back(ID);
}

int stk[N], top = 0;

ll solve(const vector<string> &s) {
  int n = s.size();
  int len = s[0].size();
  for (int i = 1; i < n; ++i)
    lcp[i] = mismatch(all(s[i - 1]), begin(s[i])).second - begin(s[i]);
  for (int i = 0; i < n; ++i)
    insert(s[i], i);
  ll res = n * (n - 1);
  top = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0, r;
    if (i) {
      while (top && lcp[i] <= lcp[stk[top]]) --top;
      stk[++top] = i;
    }
    for (int e = 1; e <= top; l = r, ++e) {
      r = stk[e];
      int lc = lcp[r];
      int rp = is_sorted_until(begin(s[i]) + lc, end(s[i])) - begin(s[i]);
      int x = 0;
      for (int j = len - 1; j >= rp; --j)
        x = c[x][s[i][j] - 'a'];
      res -= lower_bound(all(id[x]), r) - lower_bound(all(id[x]), l);
    }
  }
  top = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (i < n - 1) {
      while (top && lcp[i + 1] <= lcp[stk[top]]) --top;
      stk[++top] = i + 1;
    }
    int r = n, l;
    for (int e = 1; e <= top; ++e, r = l) {
      l = stk[e];
      int lc = lcp[l];
      int rp = is_sorted_until(begin(s[i]) + lc, end(s[i])) - begin(s[i]);
      int x = 0;
      for (int j = len - 1; j >= rp; --j)
        x = c[x][s[i][j] - 'a'];
      res -= lower_bound(all(id[x]), r) - lower_bound(all(id[x]), l);
    }
  }
  for (int i = 0; i <= nc; ++i)
    id[i].clear();
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s, t;
    cin >> s;
    t = s;
    sort(begin(t), end(t));
    equiv[t].push_back(s);
  }
  ll ans = 0;
  int sum = 0;
  for (auto &[id_str, S] : equiv) {
    sort(begin(S), end(S));
    ans += solve(S);
    ans += (ll)S.size() * sum * 1337;
    sum += S.size();
  }
  cout << ans << endl;
  return 0;
}