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

const int LOGN = 30;

vector<int> bitr(int x) {
  vector <int> a;
  for (int i = LOGN - 1; i >= 0; --i) {
    if (x & (1 << i)) {
      a.pb(1);
    } else {
      a.pb(0);
    }
  }
  return a;
}


int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;
  cin >> q;


  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;

    if (s > t) {
      cout << "NO\n";
      continue;
    }

    auto a = bitr(s), b = bitr(t);
    //cout << bitset<7>(s) << " " << bitset<7>(t) << "\n";
    bool can = true;
    int ppos = LOGN;

    int rem = 0;
    while (a.size()) {
      if (a.back() == b.back()) {
        a.pop_back();
        b.pop_back();
        continue;
      }
      if (b.back() > a.back()) {
        if (rem) {
          --rem;
          a.pop_back();
          b.pop_back();
          continue;
        }
        can = false;
        break;
      }
      if (ppos < a.size() - 1) {
        a.pop_back();
        b.pop_back();
        ++rem;
        continue;
      }
      int set_one = -1;
      for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] == 0) {
          set_one = i;
          break;
        }
      }
      if (set_one == -1) {
        can = false;
        break;
      }
      a[set_one] = 1;
      ppos = set_one;

      a.pop_back();
      b.pop_back();
    }
    cout << (can ? "YES\n" : "NO\n");
  }

}