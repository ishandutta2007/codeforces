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

int n;
int a[200007];

struct Tree {
  int t[200007 * 4];

  void build(int v, int vl, int vr) {
    t[v] = -1e9;
    if (vl < vr) {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
    }
  }

  void up(int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
      uax(t[v], val);
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
      else up(v * 2 + 2, vm + 1, vr, pos, val);
      t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  int get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr || l > r) return -1e9;
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
  }
} tr;

int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  vector<pair<int, int> > t;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    t.pb(mp(a[i] - i - 1, a[i]));
  }
  sort(all(t), [](pair<int, int> a, pair<int, int> b) {
    if (a.x == b.x) return a.y < b.y; 
    return a.x > b.x;
  });

  tr.build(0, 0, 200000);

  int ma = 0;

 // pper(t);

  for (int i = 0; i < t.size(); ++i) {
    int now = tr.get(0, 0, 200000, 0, t[i].y - 1) + 1;
    if (t[i].x <= 0) uax(now, 1);
    tr.up(0, 0, 200000, t[i].y, now);
    uax(ma, now);
  }

  cout << ma;

}