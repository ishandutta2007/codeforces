#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, pair<int, int>> last;
queue<pair<int, int>> q;
map<int, int> already;
int u, v, mod;

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % mod;
}

int power(int x, int y) {
  int result = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      result = mul(result, x);
    }
  }
  return result;
}

void insert(int x, int y, int z, int from) {
  if (already.find(x) != already.end()) {
    if (already[x] != y) {
      vector<int> result;
      int current;
      for (current = x; current != u && current != v; current = last[current].first) {
        result.push_back(last[current].second);
      }
      reverse(result.begin(), result.end());
      result.push_back(z);
      for (current = from; current != u && current != v; current = last[current].first) {
        result.push_back(last[current].second);
      }
      if (current == u) {
        reverse(result.begin(), result.end());
      }
      printf("%d\n", result.size());
      for (int i = 0; i < result.size(); ++i) {
        printf("%d%c", result[i], i == result.size() - 1 ? '\n' : ' ');
      }
      exit(0);
    }
  } else {
    already[x] = y;
    last[x] = make_pair(from, z);
    q.push(make_pair(x, y));
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d %d", &u, &v, &mod);
  if (u == v) {
    puts("0");
    return 0;
  }
  already[u] = 1;
  already[v] = 2;
  q.push(make_pair(u, 1));
  q.push(make_pair(v, 2));
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first, y = p.second;
    insert(add(x, 1), y, y, x);
    insert(sub(x, 1), y, 3 - y, x);
    insert(power(x, mod - 2), y, 3, x);
  }
  return 0;
}