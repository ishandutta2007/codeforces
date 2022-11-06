#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 5e-7;

inline bool eq (ld x, ld y) {
  return fabs(x - y) < EPS;
}

string get (int mask, int half) {
  string s = "";
  for (int i = 0; i < half; ++i) {
    if (mask & 1 << i) s += '('; else s += ')';
  }
  return s;
}

int n;
ld t_x, t_y;
tuple <ld, ld, ld> center[2][69][69];

int main() {
  cin >> n >> t_x >> t_y;
  for (int at = 0; at < 69; ++at) {
    for (int sum = 0; sum < 69; ++sum) {
      ld c_x = at + (ld) (3 * sum + 2) / (6 * sum + 3);
      ld c_y = (ld) (3 * sum * (sum + 1) + 1) / (6 * sum + 3), c_mass = sum + 0.5;
      center[0][at][sum] = make_tuple(c_x, c_y, c_mass);
    }
  }
  for (int at = 0; at < 69; ++at) {
    for (int sum = 0; sum < 69; ++sum) {
      ld c_x = at + (ld) (3 * sum - 2) / (6 * sum - 3);
      ld c_y = (ld) (3 * sum * (sum - 1) + 1) / (6 * sum - 3), c_mass = sum - 0.5;
      center[1][at][sum] = make_tuple(c_x, c_y, c_mass);
    }
  }
  int half = n >> 1;
  map <int, vector <tuple <ld, ld, int>>> f;
  for (int mask = 0; mask < 1 << half; ++mask) {
    int cur = 0, minV = 0;
    for (int i = 0; i < half; ++i) {
      if (mask & 1 << i) ++cur; else --cur;
      minV = min(minV, cur);
    }
    if (cur != minV) continue;
    minV = -minV, cur = minV;
    ld x = 0, y = 0, mass = 0;
    for (int i = 0; i < half; ++i) {
      if (mask & 1 << i) {
        auto [c_x, c_y, c_mass] = center[0][half + i][cur];
        ld new_mass = mass + c_mass;
        ld new_x = (mass * x + c_mass * c_x) / new_mass;
        ld new_y = (mass * y + c_mass * c_y) / new_mass;
        x = new_x, y = new_y, mass = new_mass, ++cur;
      } else {
        auto [c_x, c_y, c_mass] = center[1][half + i][cur];
        ld new_mass = mass + c_mass;
        ld new_x = (mass * x + c_mass * c_x) / new_mass;
        ld new_y = (mass * y + c_mass * c_y) / new_mass;
        x = new_x, y = new_y, mass = new_mass, --cur;
      }
    }
    x *= mass, y *= mass;
    // if (get(mask, half) == "())") {
    //   cerr << t_x * mass - x << " --- " << t_y * mass - y << '\n';
    // }
    f[minV].emplace_back(t_x * mass - x, t_y * mass - y, mask);
  }
  for (auto &it : f) sort(it.second.begin(), it.second.end());
  for (int mask = 0; mask < 1 << half; ++mask) {
    int cur = 0;
    bool bad = 0;
    for (int i = 0; i < half; ++i) {
      if (mask & 1 << i) ++cur; else --cur;
      if (cur < 0) {
        bad = 1;
        break;
      }
    }
    // if (get(mask, half) == "()(") {
    //   cerr << cur << '\n';
    // }
    if (bad) continue;
    if (f.find(cur) == f.end()) continue;
    // if (get(mask, half) == "()(") {
    //   cerr << cur << '\n';
    // }
    cur = 0;
    ld x = 0, y = 0, mass = 0;
    for (int i = 0; i < half; ++i) {
      if (mask & 1 << i) {
        auto [c_x, c_y, c_mass] = center[0][i][cur];
        ld new_mass = mass + c_mass;
        ld new_x = (mass * x + c_mass * c_x) / new_mass;
        ld new_y = (mass * y + c_mass * c_y) / new_mass;
        x = new_x, y = new_y, mass = new_mass, ++cur;
      } else {
        auto [c_x, c_y, c_mass] = center[1][i][cur];
        ld new_mass = mass + c_mass;
        ld new_x = (mass * x + c_mass * c_x) / new_mass;
        ld new_y = (mass * y + c_mass * c_y) / new_mass;
        x = new_x, y = new_y, mass = new_mass, --cur;
      }
    }
    x *= mass, y *= mass;
    auto &vec = f[cur];
    tuple <ld, ld, int> yo(x - t_x * mass, y - t_y * mass, 0);
    // if (get(mask, half) == "()(") {
    //   cerr << get<0>(yo) << " " << get<1>(yo) << '\n';
    // }
    int pos = lower_bound(vec.begin(), vec.end(), yo) - vec.begin();
    for (int i = max(0, pos - 5); i < min(int(vec.size()), pos + 5); ++i) {
      auto &[b_x, b_y, oth] = vec[i];
      if (eq(b_x, get<0>(yo)) and eq(b_y, get<1>(yo))) {
        string ans = get(mask, half) + get(oth, half);
        cout << ans << '\n';
        return 0;
      }
    }
  }
  return 0;
}