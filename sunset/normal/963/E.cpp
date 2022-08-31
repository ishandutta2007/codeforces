#include <bits/stdc++.h>

using namespace std;

const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};
const int md = (int) 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) {
  return (int) ((long long) x * y % md);
}

inline int inv(int a) {
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) {
    u += md;
  }
  return u;
}

vector<int>& operator -= (vector<int> &a, const vector<int> &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); ++i) {
    sub(a[i], b[i]);
  }
  return a;
}

vector<int>& operator *= (vector<int> &a, const int &b) {
  for (int i = 0; i < (int) a.size(); ++i) {
    a[i] = mul(a[i], b);
  }
  return a;
}

vector<int> operator * (const vector<int> &a, const int &b) {
  vector<int> c = a;
  return c *= b;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int r;
  cin >> r;
  vector<int> p(4);
  for (int i = 0; i < 4; ++i) {
    cin >> p[i];
  }
  int sum_p = 0;
  for (int i = 0; i < 4; ++i) {
    sum_p += p[i];
  }
  int inv_sum_p = inv(sum_p);
  for (int i = 0; i < 4; ++i) {
    p[i] = mul(p[i], inv_sum_p);
  }
  int d = r * 2 + 1, n = 0;
  vector<vector<int>> id(d, vector<int>(d, -1));
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      if ((i - r) * (i - r) + (j - r) * (j - r) <= r * r) {
        id[i][j] = n++;
      }
    }
  }
  vector<int> first(d, -1);
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      if (id[i][j] != -1 && first[i] == -1) {
        first[i] = j;
      }
    }
  }
  vector<vector<int>> coef(n, vector<int>(d + 1));
  for (int i = 0; i < d; ++i) {
    coef[id[i][first[i]]][i] = 1;
  }
  vector<vector<int>> equation;
  int invp3 = inv(p[3]);
  for (int j = 0; j < d; ++j) {
    for (int i = 0; i < d; ++i) {
      if (id[i][j] != -1) {
        vector<int> poly = coef[id[i][j]];
        sub(poly[d], 1);
        for (int k = 0; k < 3; ++k) {
          int ii = i + dx[k], jj = j + dy[k];
          if (ii >= 0 && ii < d && jj >= 0 && jj < d && id[ii][jj] != -1) {
            poly -= coef[id[ii][jj]] * p[k];
          }
        }
        if (j + 1 == d || id[i][j + 1] == -1) {
          poly[d] = (md - poly[d]) % md;
          equation.push_back(poly);
        } else {
          coef[id[i][j + 1]] = poly * invp3;
        }
      }
    }
  }
  for (int i = 0; i < d; ++i) {
    int j = i;
    while (j < d && !equation[j][i]) {
      ++j;
    }
    assert(j != d);
    if (j != i) {
      swap(equation[i], equation[j]);
    }
    int inv_value = inv(equation[i][i]);
    for (int j = i + 1; j < d; ++j) {
      if (equation[j][i]) {
        equation[j] -= equation[i] * mul(equation[j][i], inv_value);
      }
    }
  }
  vector<int> ans(d);
  for (int i = d - 1; ~i; --i) {
    ans[i] = equation[i][d];
    for (int j = i + 1; j < d; ++j) {
      sub(ans[i], mul(ans[j], equation[i][j]));
    }
    ans[i] = mul(ans[i], inv(equation[i][i]));
  }
  int res = coef[id[r][r]][d];
  for (int i = 0; i < d; ++i) {
    add(res, mul(ans[i], coef[id[r][r]][i]));
  }
  cout << res << "\n";
  return 0;
}