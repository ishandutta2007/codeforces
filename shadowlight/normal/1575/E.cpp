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
  if (a < 0) a += mod;
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


int n, k;
vector<pair<int, int> > g[200007];
int a[200007];


const int MAXN = 2e5 + 7;



const size_t MAX_BIT = 18;
const size_t MAX_SIZE = 1 << MAX_BIT;

struct FenwickTree1 {
  int t[MAX_SIZE];

  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      add(res, t[v]);
    }
    return res;
  }

  // Sum [vl..vr]
  int get(int vl, int vr) {
    if (vl > vr) return 0;
    int res = get(vr);
    if (vl > 0) {
      dec(res, get(vl - 1));
    }
    return res;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      add(t[v], val);
    }
  }
} F[2], G[2];


int RES = 0;

class CentroidDecomposition {
public:
  int n;
  int w[MAXN];
  int del[MAXN];
  
  void CalcW(int v, int p = -1) {
    w[v] = 1;
    for (auto [to, _] : g[v]) if (to != p && !del[to]) {
      CalcW(to, v);
      w[v] += w[to];
    }
  }
  
  int FindCentroid(int v, int total_w, int p = -1) {
    for (auto [to, _] : g[v]) if (to != p && !del[to] && 2 * w[to] > total_w) {
      return FindCentroid(to, total_w, v);
    } 
    return v;
  }

  void col(int v, int p, int first, int last, int co, int zn, int sum) {
    add(sum, a[v]);
    F[first].up(co, zn * sum);
    G[first].up(co, zn);
   // per(v, zn, sum);
    for (auto [to, be] : g[v]) if (to != p && !del[to]) {
      col(to, v, first, be, co + (be != last), zn, sum);
    }
  }

  void go(int v, int p, int first, int last, int co, int sum) {
    if (co > k) return;
    add(sum, a[v]);

    add(RES, F[first].get(0, k - co));
    add(RES, F[first ^ 1].get(0, k - co - 1));
    add(RES, mult(sum, G[first].get(0, k - co)));
    add(RES, mult(sum, G[first ^ 1].get(0, k - co - 1)));

    for (auto [to, be] : g[v]) if (to != p && !del[to]) {
      go(to, v, first, be, co + (be != last), sum);
    }
  }
  
  int Build(int v) {
    CalcW(v);
    int c = FindCentroid(v, w[v]); // current centroid


    for (auto [to, be] : g[c]) if (!del[to]) {
      col(to, c, be, be, 0, 1, 0);
    }


    add(RES, a[c]);
    add(RES, F[0].get(0, k));
    add(RES, F[1].get(0, k));
    add(RES, mult(a[c], G[0].get(0, k)));
    add(RES, mult(a[c], G[1].get(0, k)));



    //pper(RES)

    //exit(0);

    for (auto [to, be] : g[c]) if (!del[to]) {
      col(to, c, be, be, 0, -1, 0);

      go(to, c, be, be, 0, a[c]);
    }


  //  pper(RES)

//    exit(0);
    
    del[c] = 1;
    for (auto [to, _] : g[c]) if (!del[to]) {
      Build(to);
    }
    return c;
  }
} KEK;



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;
  readArr(a, a + n);
  for (int i = 0; i < n - 1; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    g[w1].pb(mp(w2, w3));
    g[w2].pb(mp(w1, w3));
  }

  KEK.Build(0);

  cout << RES;

}