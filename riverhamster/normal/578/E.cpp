#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <set>
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

const int N = 100005;

char s[N];
set<int> L, R;
vector<vector<int>> path[2][2];
vector<int> res;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    if (s[i] == 'L') L.insert(i);
  for (int i = 1; i <= n; ++i)
    if (s[i] == 'R') R.insert(i);
  int cnt = 0;
  while (!L.empty() || !R.empty()) {
    ++cnt;
    int i = min(L.empty() ? (int)1e9 : *L.begin(), R.empty() ? (int)1e9 : *R.begin());
    vector<int> P = {i};
    while (true) {
      if (s[i] == 'L') {
        L.erase(i);
        auto it = R.upper_bound(i);
        if (it != R.end()) i = *it;
        else break;
      }
      else {
        R.erase(i);
        auto it = L.upper_bound(i);
        if (it != L.end()) i = *it;
        else break;
      }
      P.push_back(i);
    }
    int st = (s[P.front()] == 'R');
    int ed = (s[P.back()] == 'R');
    path[st][ed].push_back(P);
  }
  printf("%d\n", cnt - 1);
  if (!path[0][0].empty() && !path[1][1].empty()) {
    vector<int> P;
    int i = path[1][1].size() > path[0][0].size();
    for (; !path[i][i].empty(); i ^= 1) {
      P.insert(P.end(), path[i][i].back().begin(), path[i][i].back().end());
      path[i][i].pop_back();
    }
    assert(path[0][0].empty() && path[1][1].empty());
    int st = s[P.front()] == 'R';
    int ed = s[P.back()] == 'R';
    path[st][ed].push_back(P);
  }
  while (path[0][1].size() > 1) {
    path[0][1].front().insert(path[0][1].front().end(), path[0][1].back().begin(), path[0][1].back().end());
    path[0][1].pop_back();
  }
  while (path[1][0].size() > 1) {
    path[1][0].front().insert(path[1][0].front().end(), path[1][0].back().begin(), path[1][0].back().end());
    path[1][0].pop_back();
  }
  int valued = 0, vi, vj;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if (!path[i][j].empty())
        vi = i, vj = j, ++valued;
  if (valued == 1) {
    for (int x : path[vi][vj].front())
      printf("%d ", x);
    putchar('\n');
    return 0;
  }
  if (!path[0][0].empty()) {
    for (const auto &P : path[0][1])
      for (int x : P) printf("%d ", x);
    for (int x : path[0][0].front()) printf("%d ", x);
    for (const auto &P : path[1][0])
      for (int x : P) printf("%d ", x);
    putchar('\n');
    return 0;
  }
  if (!path[1][1].empty()) {
    for (const auto &P : path[1][0])
      for (int x : P) printf("%d ", x);
    for (int x : path[1][1].front()) printf("%d ", x);
    for (const auto &P : path[0][1])
      for (int x : P) printf("%d ", x);
    putchar('\n');
    return 0;
  }
  if (path[0][1].empty())
    for (int x : path[1][0].front()) printf("%d ", x);
  else if (path[1][0].empty())
    for (int x : path[0][1].front()) printf("%d ", x);
  else {
    vector<int> &P0 = path[0][1].front(), &P1 = path[1][0].front();
    if (P0.back() > P1.back()) swap(P0, P1);
    for (int x : P0) printf("%d ", x);
    printf("%d ", P1.back());
    for (auto i = P1.begin(), t = prev(P1.end()); i != t; ++i)
      printf("%d ", *i);
  }
  putchar('\n');
  return 0;
}