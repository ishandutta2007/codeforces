#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) {
  return bp(a, mod - 2);
}

const int N = 1e5 + 7;

int f[N];
int rf[N];

void init() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = inv(f[i]);
  }
}

int C(int n, int k) {
  return mult(f[n], mult(rf[k], rf[n - k]));
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int odd = 0, even = 0;
  int blocks = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') continue;
    if (i + 1 < n && s[i + 1] == '1') {
      //++odd, ++even;
      ++blocks;
      ++i;
      continue;
    }
    if (i % 2) {
      ++odd;
    } else {
      ++even;
    }
  }

  cout << C(n - blocks - odd - even, blocks) << "\n";

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}