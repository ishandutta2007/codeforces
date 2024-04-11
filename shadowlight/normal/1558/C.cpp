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

vector<int> res;
vector<int> p;

void do_op(int len) {
  assert(len % 2);
  res.pb(len);
  for (int i = 0; i < len / 2; ++i) {
    swap(p[i], p[len - 1 - i]);
  }
}

void solve() {
  int n;
  cin >> n;
  res.clear();
  p.assign(n, 0);
  bool bad = false;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    if (p[i] % 2 != i % 2) {
      bad = true;
    }
  }
  if (bad) {
    cout << "-1\n";
    return;
  }

  while (n > 1) {
    for (int i = 2; i < n; i += 2) {
      if (p[i] == n - 1) {
        do_op(i + 1);
        break;
      }
    }
    int pp = 1;
    for (int i = 3; i < n; i += 2) {
      if (p[i] == n - 2) {
        do_op(i);
        pp = i;
      }
    }

    do_op(pp + 2);
    do_op(3);
    do_op(n);

    n -= 2;
  }

  auto sorted = p;
  sort(all(sorted));
  assert(sorted == p);

  cout << res.size() << "\n";
  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}