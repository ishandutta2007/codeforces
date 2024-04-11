#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int CNT = 3;
const int maxN = 210000;

int n, m;
string s, t;

vector <int> ps[26];
vector <int> pt[26];
vector <int> ds[26];
vector <int> dt[26];

vector <long long> mods[CNT][26];
vector <long long> modt[CNT][26];

long long pmod[CNT][maxN];

vector <long long> mod;
vector <long long> base;

bool is_prime(long long x) {
  if (x == 1) {
    return false;
  }
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void gen_mod(vector <long long>& mod, long long svalue) {
  int cur = svalue + rand() % 1000;
  for (long long i = cur; mod.size() < CNT; ++i) {
    if (is_prime(i)) {
      mod.push_back(i);
    }
  }
}

vector <int> convert_diff(const vector<int>& a) {
  vector <int> ret;
  if (a.size() == 0) {
    return ret;
  }
  ret.push_back(a[0]);
  for (int i = 1; i < a.size(); ++i) {
    ret.push_back(a[i] - a[i - 1]);
  }
  return ret;
}

vector <long long> get_hashing(const vector<int>& p, int idx, int len) {
  vector <long long> ret(len);
  vector <int> used(len, 0);
  for (int i = 0; i < p.size(); ++i) {
    used[p[i]] = 1;
  }
  long long curvalue = 0;
  for (int i = 0; i < len; ++i) {
    long long add = used[i];
    curvalue += add * pmod[idx][i];
    curvalue %= mod[idx];
    ret[i] = curvalue;
  }
  return ret;
}

long long get_hash(const vector<long long>& vals, int l, int r, long long mod) {
  long long hash1 = vals[r];
  long long hash2 = 0;
  if (l > 0) {
    hash2 = vals[l - 1];
  }
  return ((hash1 - hash2) % mod + mod) % mod;
}

bool equal_st(int ch, int l, int r, int ch2) {
  for (int i = 0; i < CNT; ++i) {
    long long hash1 = get_hash(mods[i][ch], l, r, mod[i]);
    long long hash2 = get_hash(modt[i][ch2], 0, m - 1, mod[i]) * pmod[i][l];
    hash2 %= mod[i];
    if (hash1 != hash2) {
      return false;
    }
  }
  return true;
}

bool check(int st) {
  map <int, int> pairs;
  for (int i = 0; i < 26; ++i) {
    int par = -1;
    if (pairs.count(i)) {
      par = pairs[i];
    } else {
      int idx = lower_bound(ps[i].begin(), ps[i].end(), st) - ps[i].begin();
      if (idx >= ps[i].size()) {
        continue;
      }
      if (ps[i][idx] > st + m - 1) {
        continue;
      }
      par = t[ps[i][idx] - st] - 'a';
    }
    if (pairs.count(par) && pairs[par] != i) {
      return false;
    }
    pairs[i] = par;
    pairs[par] = i;

    if (!equal_st(i, st, st + m - 1, par)) {
      return false;
    }
  }
  return true;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  cin >> s >> t;

  gen_mod(mod, 1000000000);
  gen_mod(base, 1000000);

  for (int i = 0; i < mod.size(); ++i) {
    pmod[i][0] = 1LL;
    for (int j = 1; j < maxN; ++j) {
      pmod[i][j] = (pmod[i][j - 1] * base[i]) % mod[i];
    }
  }

  for (int i = 0; i < n; ++i) {
    ps[s[i] - 'a'].push_back(i);
  }

  for (int i = 0; i < m; ++i) {
    pt[t[i] - 'a'].push_back(i);
  }

  for (int i = 0; i < 26; ++i) {
    ds[i] = convert_diff(ps[i]);
    dt[i] = convert_diff(pt[i]);
  }

  for (int i = 0; i < CNT; ++i) {
    for (int j = 0; j < 26; ++j) {
      mods[i][j] = get_hashing(ps[j], i, n);
      modt[i][j] = get_hashing(pt[j], i, m);
    }
  }

  vector <int> res;
  for (int i = 0; i + m - 1 < n; ++i) {
    if (check(i)) {
      res.push_back(i);
    }
  }

  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] + 1 << " ";
  }
  cout << endl;

  return 0;
}