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

const int N = 3e5 + 7;

int pos[N];
int dir[N];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> val(n, 0);
  vector<pair<int, int>> vals(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> vals[i].x;
    vals[i].y = i;
  }
  sort(all(vals));

  vector<int> rpos(n);
  for (int i = 0; i < n; ++i) {
    int x = vals[i].x;
    val[i] = x % 2;
    pos[i] = x;
    rpos[vals[i].y] = i;
  }

  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    dir[rpos[i]] = (c == 'R');
  }

  vector<int> res(n, -1);

  for (int d = 0; d < 2; ++d) {
    vector<int> st;
    for (int i = 0; i < n; ++i) {
      if (val[i] != d) continue;
      if (dir[i]) {
        st.pb(i);
      } else if (st.size() && dir[st.back()]) {
        int x = pos[st.back()], y = pos[i];
        res[st.back()] = (y - x) / 2;
        res[i] = (y - x) / 2;
        st.pop_back();
      } else {
        st.pb(i);
      }
    }
    int lt = -1, rt = -1;
    for (int x : st) {
      if (!dir[x]) {
        if (lt == -1) {
          lt = x;
        } else {
          int a = pos[lt], b = pos[x];
          res[lt] = res[x] = a + (b - a) / 2;
          lt = -1;
        }
      }
    }
    reverse(all(st));
    for (int x : st) {
      if (dir[x]) {
        if (rt == -1) {
          rt = x;
        } else {
          int a = m - pos[rt], b = m - pos[x];
          res[x] = res[rt] = a + (b - a) / 2;
          rt = -1;
        }
      }
    }
    if (lt != -1 && rt != -1) {
      res[lt] = res[rt] = (pos[lt] + 2 * m - pos[rt]) / 2;
    }
  }
  auto rres = res;
  for (int i = 0; i < n; ++i) {
    rres[vals[i].y] = res[i];
  }
  for (int x : rres) {
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