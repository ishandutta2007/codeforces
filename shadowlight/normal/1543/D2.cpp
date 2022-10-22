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
 
int k;
 
vector<int> to_repr(int x) {
  vector <int> a;
  do {
    a.pb(x % k);
    x /= k;
  } while (x);
  return a;
}
 
int to_num(vector<int> a) {
  reverse(all(a));
  int x = 0;
  for (int t : a) {
    x = x * k + t;
  }
  return x;
}
 
vector<int> add(vector<int> a, vector<int> b) {
  while (a.size() < b.size()) {
    a.pb(0);
  }
  for (int i = 0; i < (int) b.size(); ++i) {
    a[i] = (a[i] + b[i]) % k;
  }
  return a;
}

vector<int> dec(vector<int> a, vector<int> b) {
  while (a.size() < b.size()) {
    a.pb(0);
  }
  for (int i = 0; i < (int) b.size(); ++i) {
    a[i] = (a[i] - b[i] + k) % k;
  }
  return a;
}

 
void solve() {
  int n;
  cin >> n >> k;
 
  vector<int> q = to_repr(0);
  vector <int> p = to_repr(0);

  for (int i = 0; i < n; ++i) {
    auto val = to_repr(i);
    if (i % 2) {
      q = dec(p, val);
    } else {
      q = add(p, val);
    }
    p = dec(q, p);
    cout << to_num(q) << endl;
    int r;
    cin >> r;
    if (r) break;
  }  
}
 
int main(){
 
  int t;
  cin >> t;
 
  for (int i = 0; i < t; ++i) {
    solve();
  }
 
}