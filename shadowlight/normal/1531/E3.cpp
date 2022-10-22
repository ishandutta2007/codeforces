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

string s;

vector <int> res;

vector<int> sizes;

int now = 0;
bool get_sizes(int n) {
  if (n == 1) {
    return true;
  }
  int sza = n / 2;
  int szb = n - n / 2;
  get_sizes(sza);
  get_sizes(szb);

  int current = 0;
  while (now < s.size() && sza && szb) {
    if (s[now] == '0') {
      --sza;
    } else {
      --szb;
    }
    ++current;
    ++now;
  }
  if (sza && szb) {
    return false;
  }
  sizes.pb(current);
  return true;
}

int solve(int n, vector<int>& a, int pos) {
  /*cout << n << " " << pos << endl;
  for (int x : a) {
    cout << x + 1 << " ";
  }
  cout << "\n";

  cout << "PREFIX: " << s.substr(0, pos) << endl;
  cout << "========================\n";*/

  if (n == 1) {
    res.pb(a[0]);
    return pos;
  }

  int sza = n / 2;
  int szb = n - sza;

  int was = pos;
  pos -= sizes.back();
  sizes.pop_back();

  vector <int> b, c;
  int now = 0;
  for (int i = pos; i < was; ++i) {
    if (s[i] == '0') {
      b.pb(a[now++]);
    } else {
      c.pb(a[now++]);
    }
  }
  while (b.size() < sza) {
    b.pb(a[now++]);
  }
  while (c.size() < szb) {
    c.pb(a[now++]);
  }

  pos = solve(szb, c, pos);
  if (pos == -1) {
    return -1;
  }
  return solve(sza, b, pos);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> s;
/*
  for (int n = 2; n <= 1000; ++n) {
    res.clear();

    sizes.clear();
    now = 0;
    if (!get_sizes(n) || now < s.size()) {
      continue;
    }
    vector <int> a(n, 0);
    iota(all(a), 0);
    int ret = solve(n, a, s.size());
    reverse(all(res));
    
    if (res.size() == n && ret == 0) {
      cout << n << "\n";
      for (int x : res) {
        cout << x + 1 << " ";
      }
      cout << "\n";
      return 0;
    }
  }*/

  int l = 0, r = 1e5 + 7;

  while (r - l > 1) {
    int m = (l + r) / 2;

    sizes.clear();
    now = 0;
    int ret = get_sizes(m);
    if (now == s.size()) {
      r = m;
    } else {
      l = m;
    }
  }

  int n = r;
  sizes.clear();
  now = 0;
  assert(get_sizes(n));
  assert(now == s.size());

  vector <int> a(n, 0);
  iota(all(a), 0);
  int ret = solve(n, a, s.size());
  reverse(all(res));

  cout << n << "\n";
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}