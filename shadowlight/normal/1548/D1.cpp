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
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector <int> cnt(4, 0);

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x /= 2, y /= 2;
    ++cnt[(x % 2) * 2 + (y % 2)];
  }

  ll res = 0;
  for (int maska = 0; maska < 4; ++maska) {
    for (int maskb = maska; maskb < 4; ++maskb) {
      for (int maskc = maskb; maskc < 4; ++maskc) {
        int t = 0;
        if (maska != maskb) {
          ++t;
        }
        if (maskb != maskc) {
          ++t;
        }
        if (maska != maskc) {
          ++t;
        }

        if (t % 2) continue;
        
        ll cnt1 = cnt[maska];
        ll cnt2 = cnt[maskb];
        ll cnt3 = cnt[maskc];

        //cout << maska << " " << maskb << " " << maskc << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
        //cout << res << endl;

        if (maska == maskb && maskb == maskc) {
          res += cnt1 * (ll) (cnt1 - 1) * (ll) (cnt1 - 2) / 6;
          continue;
        }
        if (maska == maskb) {
          res += cnt1 * (ll) (cnt1 - 1) * (ll) cnt3 / 2;
          continue;
        }
        if (maskb == maskc) {
          res += cnt1 * (ll) cnt2 * (cnt2 - 1) / 2;
          continue;
        }
      }
    }
  }
  cout << res << "\n";
}