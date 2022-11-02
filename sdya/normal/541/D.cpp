#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

long long res = 0;
long double eps = 1e-6;

bool is_prime(long long val) {
  if (val == 1) {
    return false;
  }
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i == 0) {
      return false;
    }
  }
  return true;
}

int check(long long v, long long x, long long k) {
  long long cur = 1;
  for (int i = 0; i < k; ++i) {
    if (cur > x / v) {
      return 1;
    }
    cur *= v;
  }
  if (cur < x) {
    return -1;
  }
  return 0;
}

long long bs(long long x, long long k) {
  long long l = 1, r = x;
  long long res = 1;
  while (l <= r) {
    long long key = (l + r) / 2;
    if (check(key, x, k) != 1) {
      res = key;
      l = key + 1;
    } else {
      r = key - 1;
    }
  }
  if (check(res, x, k) == 0) {
    return res;
  }
  return -1;
}

long long check_root(long long x, long long k) {
  long double value = pow((long double) x, (long double)1. / k);
  long long vl[3];
  vl[0] = (long long)(value - 1);
  vl[1] = (long long)(value);
  vl[2] = (long long)(value + 1);
  for (int i = 0; i < 3; ++i) {
    if (vl[i] <= 0) continue;
    long double val = pow((long double)(vl[i]), (long double)k);
    if (fabs(val - x) < eps) {
      return vl[i];
    }
  }
  return -1;
}

long long fnd(long long d) {
  long long nval = d - 1;
  for (int k = 50; k >= 1; --k) {
    long long v = bs(nval, k);
    if (v == -1) {
      continue;
    }
    if (is_prime(v)) {
      return v;
    }
  }
  return -1;
}

int used[1200000];
const int maxN = 1100000;
bool havebig = false;

void rec(int have, vector <vector <long long> >& a, long long rst) {
  if (rst == 1) {
    ++res;
    return;
  }
  for (int i = have; i < a.size(); ++i) {
    for (int j = 0; j < a[i].size(); ++j) {
      if (rst % a[i][j] == 0) {
        rec(i + 1, a, rst / a[i][j]);
      }
    }
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  long long a;
  cin >> a;

  vector <long long> divs;
  for (long long i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      if (i >= 3)
      divs.push_back(i);
      if (i * i != a) {
        if (a / i >= 3)
        divs.push_back(a / i);
      }
    }
  }

  sort(divs.begin(), divs.end());
  divs.resize(unique(divs.begin(), divs.end()) - divs.begin());

  vector <long long> prs;
  vector <long long> ndivs;
  map<long long, vector<long long> > dvs;
  for (int i = 0; i < divs.size(); ++i) {
    long long x = fnd(divs[i]);
    if (x != -1) {
      prs.push_back(x);
      ndivs.push_back(divs[i]);
      dvs[x].push_back(divs[i]);
    }
  }

  vector <vector <long long> > nw;

  for (map<long long, vector <long long> >::iterator it = dvs.begin(); it != dvs.end(); ++it) {
    nw.push_back(it->second);
  }

  memset(used, 0, sizeof(used));
  reverse(nw.begin(), nw.end());
  rec(0, nw, a);
  cout << res << endl;
  return 0;
}