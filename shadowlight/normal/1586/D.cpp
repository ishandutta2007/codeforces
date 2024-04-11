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


int main(){
  int n;
  cin >> n;

  vector<int> p(n, -1);
  vector<int> positions;
  vector<bool> used(n, false);

  int pos = n - 1;
  int delta = 0;
  while (pos > 0) {
    int k = 0;
    if (positions.size() < n - 1) {
      cout << "? ";
      for (int i = 0; i < pos; ++i) {
        if (p[i] != -1) {
          cout << n << " ";
        } else {
          cout << n - positions.size() - 1 << " ";
        }
      }
      cout << n << " ";
      for (int i = pos + 1; i < n; ++i) {
        cout << n << " ";
      }
      cout << endl;
      
      cin >> k;
    }

    if (!k) {
      p[pos] = n - positions.size() - 1 - delta;
      used[p[pos]] = true;
      for (int i = 0; i < (int) positions.size(); ++i) {
        p[positions[i]] = p[pos] + i + 1;
        used[p[positions[i]]] = true;
      }
      delta += positions.size() + 1;
      positions.clear();
      //per(p);
      while (pos > 0 && p[pos] != -1) --pos;
    } else {
      positions.pb(k - 1);
    }
  }
  if (p[0] == -1) {
    for (int i = 0; i < n; ++i) {
      if (!used[i]) p[0] = i;
    }
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) {
    cout << p[i] + 1 << " ";
  }
  cout << endl;
}