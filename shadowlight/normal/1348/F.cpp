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

struct Tree {
  int n;
  vector<int> t;

  Tree(int n, vector<int> a) : n(n), t(2 * n) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = a[i];
    }
    for (int i = n - 1; i >= 1; --i) {
      t[i] = min(t[2 * i], t[2 * i + 1]);
    }
  }

  int get(int l, int r) {
    int res = n;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        res = min(res, t[l++]);
      }
      if (r % 2 == 0) {
        res = min(res, t[r--]);
      }
    }
    return res;
  }
};

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  vector <int> a(n), b(n);
  vector<vector<pair<int, int>>> ends(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
    ends[a[i]].pb({b[i], i});
  }
  set<pair<int, int>> q;
  vector<int> p(n);
  vector<int> rp(n);

  for (int x = 0; x < n; ++x) {
    for (auto t : ends[x]) {
      q.insert(t);
    }
    assert(q.size());
    int pos = q.begin()->y;
    q.erase(q.begin());
    p[pos] = x;
    rp[x] = pos;
  }
  vector<int> c;
  for (int i = 0; i < n; ++i) {
    c.pb(a[rp[i]]);
  }
  Tree tree(n, c);

  for (int x = 0; x < n; ++x) {
    int aa = a[rp[x]], bb = b[rp[x]];

    int lpos = tree.get(x + 1, bb);
    if (lpos <= x) {
      cout << "NO\n";
      for (int x : p) {
        cout << x + 1 << " ";
      }
      cout << "\n";

      for (int y = x + 1; y <= bb; ++y) {
        int ad = a[rp[y]];
        if (ad <= x) {
          swap(p[rp[x]], p[rp[y]]);
          break;
        }
      }

      for (int x : p) {
        cout << x + 1 << " "; 
      }
      cout << "\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int x : p) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}