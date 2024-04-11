#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, need;
  scanf("%d %d", &n, &need);
  vector<int> disc, l(n), r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &l[i], &r[i]);
    disc.push_back(l[i]);
    disc.push_back(r[i]);
  }
  sort(disc.begin(), disc.end());
  disc.erase(unique(disc.begin(), disc.end()), disc.end());
  int m = disc.size();
  vector<vector<int>> event(m);
  for (int i = 0; i < n; ++i) {
    l[i] = lower_bound(disc.begin(), disc.end(), l[i]) - disc.begin();
    r[i] = lower_bound(disc.begin(), disc.end(), r[i]) - disc.begin();
    event[l[i]].push_back(i);
    event[r[i]].push_back(i + n);
  }

  set<pair<pair<int, int>, int>> ranges;
  vector<vector<pair<int, int>>> modifies(n);

  auto insert_range = [&](int l, int r, int value) {
    if (l <= r) {
      ranges.insert(make_pair(make_pair(l, r), value));
    }
  };

  auto erase_range = [&](int l, int r, int value) {
    if (l <= r) {
      auto it = ranges.lower_bound(make_pair(make_pair(l, r), 0));
      if (it->second != value) {
        modifies[r].emplace_back(l, disc[value] - disc[it->second]);
      }
      ranges.erase(it);
    }
  };

  set<int> s;
  s.insert(-1);
  s.insert(n);
  insert_range(0, n - 1, 0);
  for (int i = 0; i < m; ++i) {
    for (auto x : event[i]) {
      if (x < n) {
        auto it = s.insert(x).first;
        erase_range(*prev(it) + 1, *next(it) - 1, i);
        insert_range(*prev(it) + 1, *it - 1, i);
        insert_range(*it + 1, *next(it) - 1, i);
      } else {
        x -= n;
        auto it = s.find(x);
        erase_range(*prev(it) + 1, *it - 1, i);
        erase_range(*it + 1, *next(it) - 1, i);
        insert_range(*prev(it) + 1, *next(it) - 1, i);
        s.erase(it);
      }
    }
  }

  int low = 0, high = disc.back() - disc.front();
  long long answer = 0;
  while (low <= high) {
    int mid = low + high >> 1;
    vector<pair<long long, long long>> tag(n);
    long long now = 0, sum = 0, chosen = 0, result = 0;
    for (int r = n - 1, l = n - 1; ~r; --r) {
      for (auto e : modifies[r]) {
        if (e.first <= l) {
          now += e.second;
          sum -= (long long)(e.first - 1) * e.second;
          tag[e.first].first -= e.second;
          tag[e.first].second += (long long)(e.first - 1) * e.second;
        }
      }
      while (~l && (l > r || now > mid)) {
        now += tag[l].first;
        sum += tag[l].second;
        --l;
      }
      if (!~l) {
        break;
      }
      chosen += l + 1;
      result += now * l + sum;
    }
    if (chosen >= need) {
      answer = (long long)(disc.back() - disc.front()) * need - result + (chosen - need) * mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  printf("%lld\n", answer);
  return 0;
}