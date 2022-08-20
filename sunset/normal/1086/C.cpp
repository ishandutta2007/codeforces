#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char *s) {
  return to_string((string)s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int m;
  cin >> m;
  string s, a, b;
  cin >> s >> a >> b;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    s[i] -= 'a';
    a[i] -= 'a';
    b[i] -= 'a';
  }
  vector<int> p(m, -1);
  vector<int> q(m, -1);
  auto free = [&]() {
    for (int i = 0, j = 0; i < m; ++i) {
      if (!~p[i]) {
        while (~q[j]) {
          ++j;
        }
        p[i] = j;
        q[j] = i;
      }
    }
    puts("YES");
    for (int i = 0; i < m; ++i) {
      putchar(p[i] + 'a');
    }
    putchar(10);
  };
  auto check_low = [&]() {
    for (int i = 0, j = m - 1; i < n; ++i) {
      if (~p[s[i]]) {
        if (p[s[i]] > a[i]) {
          free();
          return true;
        }
        if (p[s[i]] < a[i]) {
          return false;
        }
      } else {
        while (~q[j]) {
          --j;
        }
        p[s[i]] = j;
        q[j] = s[i];
        --i;
      }
    }
    free();
    return true;
  };
  auto check_high = [&]() {
    for (int i = 0, j = 0; i < n; ++i) {
      if (~p[s[i]]) {
        if (p[s[i]] < b[i]) {
          free();
          return true;
        }
        if (p[s[i]] > b[i]) {
          return false;
        }
      } else {
        while (~q[j]) {
          ++j;
        }
        p[s[i]] = j;
        q[j] = s[i];
        --i;
      }
    }
    free();
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (!~p[s[i]]) {
        p[s[i]] = a[i];
        if (~q[a[i]]) {
          puts("NO");
          return;
        }
        q[a[i]] = s[i];
      }
      if (p[s[i]] != a[i]) {
        puts("NO");
        return;
      }
    } else if (~p[s[i]]) {
      if (p[s[i]] > a[i] && p[s[i]] < b[i]) {
        free();
        return;
      }
      if (p[s[i]] == a[i]) {
        if (!check_low()) {
          puts("NO");
          return;
        }
        return;
      }
      if (p[s[i]] == b[i]) {
        if (!check_high()) {
          puts("NO");
          return;
        }
        return;
      }
      puts("NO");
      return;
    } else {
      for (int j = a[i] + 1; j < b[i]; ++j) {
        if (!~q[j]) {
          p[s[i]] = j;
          q[j] = s[i];
          free();
          return;
        }
      }
      if (!~q[a[i]]) {
        vector<int> np = p;
        vector<int> nq = q;
        p[s[i]] = a[i];
        q[a[i]] = s[i];
        if (check_low()) {
          return;
        }
        p = np;
        q = nq;
      }
      if (!~q[b[i]]) {
        p[s[i]] = b[i];
        q[b[i]] = s[i];
        if (check_high()) {
          return;
        }
      }
      puts("NO");
      return;
    }
  }
  free();
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}