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

const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n), b(n);
  vector<pair<int, int>> c(n);
  int win1 = n - 1, win2 = n - 1;
  for (int i = 0; i < n; ++i) {
    cin >> c[i].x;
    a[i] = {c[i].x, i};
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i].y;
    b[i] = {c[i].y, i};
  }
  sort(all(a)), sort(all(b));

  vector <int> pos1(n), pos2(n);
  //per(a, b);
  for (int i = 0; i < n; ++i) {
    pos1[a[i].y] = i;
    pos2[b[i].y] = i;
  }
  vector<int> b1(n + 1, INF), b2(n + 1, INF);
  for (int i = n - 1; i >= 0; --i) {
    b1[i] = min(c[a[i].y].y, b1[i + 1]);
    b2[i] = min(c[b[i].y].x, b2[i + 1]);
  }

  while (true) {
    int was1 = win1, was2 = win2;
    int nxt1 = b2[win1];
    int nxt2 = b1[win2];

    win1 = upper_bound(all(a), mp(nxt1, INF)) - a.begin() - 1;
    win2 = upper_bound(all(b), mp(nxt2, INF)) - b.begin() - 1;

    if (win1 == was1 && win2 == was2) break;
  }

  for (int i = 0; i < n; ++i) {
    //per(pos1[i], pos2[i]);
    if (pos1[i] >= win1 || pos2[i] >= win2) {
      cout << "1";
    } else {
      cout << "0";
    }
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