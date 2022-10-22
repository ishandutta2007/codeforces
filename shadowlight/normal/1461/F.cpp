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
 
const int LOGN = 22;

const int INF = 1e6 + 7;

void upd(int &a, int b) {
  a = max(a, b);
  a = min(a, INF);
}

int stupid(vector<int>& a) {
  int res = 0;
  int n = a.size();
  for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
    vector <int> st(a[0]);
    for (int i = 0; i + 1 < n; ++i) {
      if (mask & (1 << i)) {
        st.back() *= a[i];
      } else {
        st.pb(a[i]);
      }
    }
    int now = 0;
    for (int x : st) {
      now += x;
    }
    res = max(res, now);
  }
  return res;
}

void solve(vector<int> &a) {
  if (!a.size()) return;

  int n = a.size();
  a.pb(0);
  ++n;

 vector <vector<int>> dp(n + 1, vector<int>(LOGN, -INF));
 dp[0][0] = 0;
 vector<int> st;
 for (int i = 0; i < n; ++i) {
    int mlt = 1;
    for (int j = 0; j < LOGN; ++j) {
      if (a[i] <= 1) {
        if (a[i]) upd(dp[i + 1][j], dp[i][j]);
        upd(dp[i + 1][0], dp[i][0] + a[i]);
        if (j) upd(dp[i + 1][0], dp[i][j] + mlt + a[i]);
      } else {
        if (j + 1 < LOGN) upd(dp[i + 1][j + 1], dp[i][j]);
        upd(dp[i + 1][j], dp[i][j]);
      }
      if (j < st.size()) {
        mlt *= st[st.size() - 1 - j];
        mlt = min(mlt, INF);
      } else {
        break;
      }
    }
    if (a[i] > 1) {
      st.pb(a[i]);
    }
 }

 vector <char> ops;
 if (dp[n][0] == INF) {
  int l = 0;
  while (l + 1 < n && a[l] == 1) {
    ops.pb('+');
    ++l;
  }
  int r = n - 2;
  while (r >= l && a[r] == 1) {
    --r;
  }
  for (int i = l; i < r; ++i) {
    ops.pb('*');
  }
  for (int i = r; i + 1 < n; ++i) {
    ops.pb('+');
  }
  assert(ops.size() == n - 1);

  a.pop_back();
  ops.pop_back();
  --n;
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i + 1 != n) {
      cout << ops[i];
    }
  }
  return;
 }

 int now = 0;
 int res = dp[n][0];
 pper(res);
 //assert(stupid(a) == res);

 for (int i = n - 1; i > 0; --i) {
    //per(i, now);
    if (now > 1 || (now == 1 && a[i] == 1)) {
      if (a[i] > 1) {
        --now;
        st.pop_back();
      }
      ops.pb('*');
      continue;
    } 
    ops.pb('+');
    if (now) {
      --now;
      st.pop_back();
      continue;
    }

    int mlt = 1;
    int nxt = 0;
    for (int j = 0; j < LOGN; ++j) {
      if (j && dp[i + 1][0] == dp[i][j] + mlt + a[i]) {
        nxt = j;
        break;
      }
      if (j < st.size()) {
        mlt *= st[st.size() - 1 - j];
        mlt = min(mlt, INF);
      } else {
        break;
      }
    }
    now = nxt;
 }
  reverse(all(ops));
  assert(ops.size() == n - 1);
  a.pop_back();
  ops.pop_back();
  --n;
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i + 1 != n) {
      cout << ops[i];
    }
  }
}

int main(){
#ifdef LOCAL
 freopen("F_input.txt", "r", stdin);
 //freopen("O_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 int n;
 cin >> n;
 vector <int> a(n);
 for (int i = 0; i < n; ++i) {
  cin >> a[i];
 }
 
 int mask = 0;
 
 string s;
 cin >> s;
 
 for (char c : s) {
  if (c == '-') {
    mask |= 1;
  } else if (c == '+') {
    mask |= 2;
  } else {
    mask |= 4;
  }
 }
 if ((mask & 3) == 3) {
  mask ^= 1;
 }

 if (mask == 1 || mask == 2 || mask == 4) {
  char op = (mask == 1 ? '-' : (mask == 2 ? '+' : '*'));
  for (int i = 0; i + 1 < a.size(); ++i) {
    cout << a[i] << op;
  }
  cout << a.back();
  return 0;
 }

 if (mask & 1) {
  bool was_zero = false;
  cout << a[0];
  for (int i = 1; i < n; ++i) {
    if (!a[i]) {
      cout << "-";
    } else {
      cout << "*";
    }
    cout << a[i];
  }
  return 0;
 } 
 assert(mask == 6);

 vector <int> b;

 for (int i = 0; i < n; ++i) {
  if (a[i] == 0) {
    solve(b);
    if (b.size()) {
      cout << "+";
    }
    cout << "0";
    if (i + 1 < n) {
      cout << "+";
    }
    b.clear();
  } else {
    b.pb(a[i]);
  }
 }
 solve(b);
 //cout << "1\n";
}