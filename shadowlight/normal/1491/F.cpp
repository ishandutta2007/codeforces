#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
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
  int n;
  cin >> n;

  int pos = -1;

  int qs = 0;

  for (int i = 1; i < n; ++i) {
    cout << "? " << i << " " << 1 << "\n";
    for (int j = 0; j < i; ++j) {
      cout << j + 1 << " ";
    }
    cout << "\n";
    cout << i + 1 << endl;

    ++qs;
    int power;
    cin >> power;
    if (power != 0) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    while (true) {}      
  }

  vector <int> res;

  for (int i = pos + 1; i < n; ++i) {
    cout << "? 1 1\n";
    cout << pos + 1 << "\n";
    cout << i + 1 << endl;

    ++qs;
    
    int power;
    cin >> power;
    if (power == 0) {
      res.pb(i);
    }
  }
  int sec = -1;

  int l = 0, r = pos + 1;
  while (r - l > 1) {
    int len = (l + r) / 2;
    int total = pos + 1;
    cout << "? " << len << " " << 1 << "\n";
    for (int i = 0; i < len; ++i) {
      cout << i + 1 << " ";
    }
    cout << "\n";

    cout << pos + 1 << endl;

    ++qs;

    int power;
    cin >> power;
    if (power != 0) {
      r = len;
    } else {
      l = len;
    }
  }
  if (r != pos + 1) {
    sec = r - 1;
  }

  for (int i = 0; i < pos; ++i) {
    if (i != sec) {
      res.pb(i);
    }
  }

  if (qs > n + (int)log2(n)) {
    while (true) {}
  }

  cout << "! " << res.size() << " ";
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << endl;
}

int main(){

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}