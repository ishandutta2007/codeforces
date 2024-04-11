#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 260;

string f[N], t[N], r[N];

inline string Min(string s, string t) {
  if (s == "" || t == "") {
    return s + t;
  }
  if (s.length() != t.length()) {
    return s.length() < t.length() ? s : t;
  }
  return min(s, t);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  f[0b00001111] = "x", f[0b00110011] = "y", f[0b01010101] = "z";
  for (int c = 3, s = 3; ; ) {
    for (int i = 0; i < 256; ++i) {
      if (f[i ^ 255] != "") {
        f[i] = Min(f[i], "!" + f[i ^ 255]);
      }
    }
    for (int i = 0; i < 256; ++i) {
      if (r[i] != "") {
        f[i] = Min(f[i], "(" + r[i] + ")");
      }
    }
    for (int i = 0; i < 256; ++i) {
      t[i] = Min(t[i], f[i]);
    }
    for (int i = 0; i < 256; ++i) {
      if (t[i] != "") {
        for (int j = 0; j < 256; ++j) {
          if (t[j] != "") {
            t[i & j] = Min(t[i & j], t[i] + "&" + t[j]);
          }
        }
      }
    }
    for (int i = 0; i < 256; ++i) {
      r[i] = Min(r[i], t[i]);
    }
    for (int i = 0; i < 256; ++i) {
      if (r[i] != "") {
        for (int j = 0; j < 256; ++j) {
          if (r[j] != "") {
            r[i | j] = Min(r[i | j], r[i] + "|" + r[j]);
          }
        }
      }
    }
    int C = 0, S = 0;
    for (int i = 0; i < 256; ++i) {
      if (r[i] != "") {
        ++C, S += r[i].length();
      }
      if (f[i] != "") {
        ++C, S += f[i].length();
      }
      if (t[i] != "") {
        ++C, S += t[i].length();
      }
    }
    if (c == C && s == S) {
      break;
    }
    c = C, s = S;
  }
  int T;
  for (Read(T); T; --T) {
    char str[10];
    scanf("%s", str);
    int msk = 0;
    for (int i = 0; i < 8; ++i) {
      msk = msk << 1 | str[i] - '0';
    }
    for (int i = 0; i < r[msk].length(); ++i) {
      putchar(r[msk][i]);
    }
    putchar(10);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}