#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int q;
  scanf("%d", &q);
  map<ll, int> id;
  map<pair<int, int>, int> answer;
  vector<set<pair<int, int>>> s;
  int total = 0, result = 0;
  while (q--) {
    int type, x, y;
    scanf("%d %d %d", &type, &x, &y);
    if (type == 1) {
      ++result;
      ll dist = (ll)x * x + (ll)y * y;
      if (id.find(dist) == id.end()) {
        id[dist] = total++;
        s.push_back(set<pair<int, int>> ());
      }
      int gcd = __gcd(x, y), i = id[dist];
      ++answer[make_pair(x / gcd, y / gcd)];
      for (auto p : s[i]) {
        int px = p.first, py = p.second;
        int mx = x + px, my = y + py;
        gcd = __gcd(mx, my);
        answer[make_pair(mx / gcd, my / gcd)] += 2;
      }
      s[i].insert(make_pair(x, y));
    } else if (type == 2) {
      --result;
      ll dist = (ll)x * x + (ll)y * y;
      int gcd = __gcd(x, y), i = id[dist];
      --answer[make_pair(x / gcd, y / gcd)];
      s[i].erase(make_pair(x, y));
      for (auto p : s[i]) {
        int px = p.first, py = p.second;
        int mx = x + px, my = y + py;
        gcd = __gcd(mx, my);
        answer[make_pair(mx / gcd, my / gcd)] -= 2;
      }
    } else {
      int gcd = __gcd(x, y);
      printf("%d\n", result - answer[make_pair(x / gcd, y / gcd)]);
    }
  }
  return 0;
}