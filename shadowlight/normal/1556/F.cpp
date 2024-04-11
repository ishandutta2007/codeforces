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

int inv(int a) {
  return bp(a, mod - 2);
}


int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> lose(n, vector<int>(1 << n, 0));

  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) continue;
      
      int p = 1;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          p = mult(p, mult(a[j], inv(a[i] + a[j])));
        }
      }
      lose[i][mask] = p;
    }
  }

  vector <int> value(1 << n, 0);
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        value[i] = j;
        break;
      }
    }
  }

  int res = 0;
  vector <vector<int>> good(n, vector<int>(1 << n));
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if ((mask & (1 << i))) continue;
      int p = lose[i][mask];

      //per("CUR", i, mask);

      int nmask = mask & (mask - 1);
      while (nmask) {
        int xmask = mask ^ nmask;
        int pp = mult(good[i][nmask], lose[i][xmask]);

        int tmask = nmask;
        while (tmask) {
          int pos = value[tmask];
          pp = mult(pp, lose[pos][xmask]);
          tmask &= (tmask - 1);
        }

        add(p, pp);
        nmask = (nmask - 1) & mask;
      }

      good[i][mask] = (1 + mod - p) % mod;

      if ((mask ^ (1 << i)) == (1 << n) - 1) {
        add(res, good[i][mask]);
      }
    }
  }
  cout << res << "\n";
}