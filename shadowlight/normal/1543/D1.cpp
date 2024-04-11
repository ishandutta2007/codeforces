#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

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

void solve() {
  int n, k;
  cin >> n >> k;

  int m = 0;
  for (int i = 0; i < n; ++i) {
    int x = i ^ m;
    cout << x << endl;
    int r;
    cin >> r;
    if (r) break;
    m ^= x;
  }  
}

int main(){

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}