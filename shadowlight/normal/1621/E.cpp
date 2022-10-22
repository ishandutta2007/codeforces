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
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a), greater<int>());
  while (a.size() > m) a.pop_back();
  reverse(all(a));

  vector <pair<int, int>> values(m);
  vector <vector<int>> groups(m);
  vector<ll> sums(m);

  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    ll sum = 0;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      groups[i].pb(x);
      sum += x;
    }
    int val = sum / k;
    if (sum % k) ++val;

    sums[i] = sum;
    values[i] = {val, i};
  }
  sort(all(values));

  vector <vector<int>> can(m + 1, vector<int>(3, 0));

  for (int i = m - 1; i >= 0; --i) {
    for (int dx = -1; dx <= 1; ++dx) {
      if (i + dx < 0 || i + dx > m) continue;
      if (a[i] < values[i + dx].x) continue;
      can[i][dx + 1] = can[i + 1][dx + 1] + 1;
    }
  }
  vector<string> res(m);

  for (int i = 0; i < m; ++i) {
    int ind = values[i].y;

    for (int p : groups[ind]) {
      ll nsum = sums[ind] - p;
      int nsz = groups[ind].size() - 1;

      int nval = nsum / nsz;
      if (nsum % nsz) ++nval;

      int j = int(lower_bound(all(values), mp(nval, -1)) - values.begin())- 1;

      bool canw = true;

      if (i <= j) {
        canw &= (a[j] >= nval);
        canw &= (can[0][1] >= i);
        canw &= (can[i][2] >= (j - i));
        canw &= (can[j + 1][1] >= (m - j - 1));
      } else {
        canw &= (a[j + 1] >= nval);
        canw &= (can[0][1] >= j + 1);
        canw &= (can[j + 2][0] >= (i - j - 1));
        canw &= (can[i + 1][1] >= (m - i - 1));
      }

      //per(ind, p, canw);

      res[ind] += (char) ('0' + canw);
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << res[i];
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}