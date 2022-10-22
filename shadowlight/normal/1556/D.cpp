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

vector<int> vals = {1, 6, 4, 2, 3, 5, 4};

int main(){
  int n, k;
  cin >> n >> k;

  int ors = -1, ands = -1;
  vector<int> xors(n);

  for (int i = 0; i + 1 < n; ++i) {
    cout << "and " << 1 << " " << i + 2 << endl;

    int x;
    cin >> x;
    //x = vals[0] & vals[i + 1];

    per(x);

    cout << "or " << 1 << " " << i + 2 << endl;
  
    int y;
    cin >> y;
    //y = vals[0] | vals[i + 1];

    if (ors == -1) {
      ors = y, ands = x;
    } else {
      ands |= x;
      ors &= y;
    }
    xors[i + 1] = y ^ x;
  }

  cout << "and 2 3" << endl;
  int x;
  cin >> x;
  //x = vals[1] & vals[2];

  cout << "or 2 3" << endl;
  int y;
  cin >> y;
  //y = vals[1] | vals[2];

  int val = ands;
  pper(val);
  for (int i = LOGN - 1; i >= 0; --i) {
    if (ands & (1 << i)) continue;
    if (!(ors & (1 << i))) continue;

    if (!(y & (1 << i))) {
      val |= (1 << i);
    } 
  }

  vector<int> a = {val};
  for (int i = 1; i < n; ++i) {
    a.pb(val ^ xors[i]);
  }
  //per(a);

  sort(all(a));
  cout << "finish " << a[k - 1] << endl;
}