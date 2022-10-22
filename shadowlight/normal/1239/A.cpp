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
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector <vector<int>> cnt(n + m + 2, vector<int>(4, 0));
  // 00 01 10 11
  cnt[2][0] = 1;
  cnt[2][1] = 1;
  cnt[2][2] = 1;
  cnt[2][3] = 1;
  for (int i = 2; i <= n + m; ++i) {
    add(cnt[i + 1][1], cnt[i][0]);

    add(cnt[i + 1][2], cnt[i][1]);
    add(cnt[i + 1][3], cnt[i][1]);
    
    add(cnt[i + 1][0], cnt[i][2]);
    add(cnt[i + 1][1], cnt[i][2]);

    add(cnt[i + 1][2], cnt[i][3]);
  }

  int res = 2;

  for (int it = 0; it < 2; ++it) {
    for (int i = 0; i + 1 < n; ++i) {
      int a = i + 1, b = n - i - 1;

      for (int it = 0; it < 2; ++it) {
        int mlt = 1;
        /*if (a > 1) {
          int now = 0;
          if (!it) {
            now = cnt[a][2];
          } else {
            now = cnt[a][1];
          }
          mlt = mult(mlt, now);
        }*/

        if (b > 1) {
          int now = 0;
          if (!it) {
            now = cnt[b][2];
          } else {
            now = cnt[b][1];
          }
          mlt = mult(mlt, now);
        }
        //per(i, n, it, mlt);
        add(res, mlt);
      }

    }
    swap(n, m);
  }
  cout << res << "\n";
}