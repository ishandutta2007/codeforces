#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int MAXN =  1 << 19;
const int inf = 1 << 30;
typedef long long ll;
pair<char, int> input[MAXN];
map<int, int> mp;
map<int, int> imp;
multiset<int> s;
ll bit[MAXN];
ll ask(int idx) {
  ll ret = 0;
  while (idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

void inc(int idx, int val) {
  while (idx < MAXN) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}

int bigeels() {
  int ret = 0;
  int idx = 0;
  while (true) {
    ll sum = ask(idx);
    if (sum >= inf) break;
    auto k = s.upper_bound(imp[idx]);
    if (k == s.end()) break;
    if (*k > 2 * sum) {
      // printf("%d is big eel\n", *k);
      ++ret;
    } else {
      // printf("%d is small eel\n", *k);
    }
    k = s.upper_bound(sum + *k);
    --k;
    idx = mp[*k];
  }
  return ret;
}

int qmap[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %c %d", &(input[i].first), &(input[i].second));
    mp[input[i].second] = 0;
    // printf("read %c %d\n", input[i].first, input[i].second);
  }
  int cnt = 0;
  for (auto a: mp) {
    mp[a.first] = ++cnt;
    imp[cnt] = a.first;
    // printf("%d = %d\n", cnt, a.first);
  }

  int pop = 0;
  for(int i = 0; i < n; ++i) {
    int val = input[i].second;
    int idx = mp[val];
    if (input[i].first == '+') {
      ++pop;
      s.insert(val);
      inc(idx, val);
    } else {
      --pop;
      s.erase(s.find(val));
      inc(idx, -val);
    }

    int ans = pop - bigeels();
    printf("%d\n", ans);
  }

}