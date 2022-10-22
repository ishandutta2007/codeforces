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

vector<int> ops;
vector<int> a;

void do_op(int index) {
  assert(index + 2 < a.size() && index >= 0);
  ops.pb(index);
  int val = a[index] ^ a[index + 1] ^ a[index + 2];
  a[index] = a[index + 1] = a[index + 2] = val;
}

void solve() {
  int n;
  cin >> n;
  a.assign(n, 0);
  deque<int> groups;
  int cnt = 1;
  ops.clear();

  int xr = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    xr ^= a[i];
  }

  if (xr == 1) {
    cout << "NO\n";
    return;
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      groups.pb(cnt);
      cnt = 1;
    } else {
      cnt++;
    }
  }
  groups.pb(cnt);

  if (a[0] && a.back()) {
    int sum = groups[0];
    if (sum % 2) {
      groups.pop_front();
      while (groups.size() > 1) {
        int now = groups.front();
        groups.pop_front();

        int nxt = groups.front();
        groups.pop_front();

        while (now > 1) {
          do_op(sum - 1);
          sum += 2;
          now -= 2;
        }
        if (now == 1) {
          do_op(sum - 1);
          sum -= 1;
          break;
        }
        sum += nxt;

        if (sum % 2 == 0) {
          groups.push_front(sum);
          break;
        }
      }
    }
  }

  groups.clear();
  cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      groups.pb(cnt);
      cnt = 1;
    } else {
      cnt++;
    }
  }
  groups.pb(cnt);

  if (groups.size() == 1 && a[0]) {
    cout << "NO\n";
    return;
  }

  if (a[0] && a.back()) {
    assert(groups[0] % 2 == 0);
    while (groups[0]) {
      do_op(groups[0] - 2);
      groups[0] -= 2;
    }
  }
  assert(!a[0] || !a.back());

  if (!a[0]) {
    for (int i = 0; i + 2 < n; ++i) {
      if (!a[i + 1]) continue;
      if (!a[i + 2]) {
        do_op(i + 1);
      }
      if (a[i + 1]) {
        do_op(i);
      }
    }
  } else {
    for (int i = n - 1; i >= 2; --i) {
      assert(!a[i]);
      if (!a[i - 1]) continue;
      if (!a[i - 2]) {
        do_op(i - 3);
      }
      if (a[i - 1]) {
        do_op(i - 2);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    assert(!a[i]);
  }
  assert(ops.size() <= n);

  cout << "YES\n";
  cout << ops.size() << "\n";
  for (int x : ops) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}