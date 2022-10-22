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

const int N = 157;

string dp[N][10];

bool lower(string a, string b) {
  if (a.size() == b.size()) {
    return a < b;
  }
  return a.size() < b.size();
}

string find_one(int sum) {
  string res = "";
  while (sum >= 9) {
    res += '9';
    sum -= 9;
  }
  reverse(all(res));
  if (sum) res += (char) (sum + '0');
  reverse(all(res));
  return res;
}

string find_one_good(int sum) {
  string res = "";
  while (sum >= 9) {
    res += '9';
    sum -= 9;
  }
  if (sum) {
    if (res.size()) {
      res[0] -= (8 - sum);
      res += '8';
    } else {
      res += (char) (sum + '0');
    }
  } else if (res.size()) {
    res.pop_back();
    res = "1" + res + "8";
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;

  string res = "#";

  for (int d = 0; d < 10; ++d) {
    if (d + k <= 9) {
        int lst = 0;
        for (int i = 0; i <= k; ++i) {
          lst += (d + i);
        }
        if (lst > n || (n - lst) % (k + 1)) continue;
        string upd = find_one((n - lst) / (k + 1));
        upd += (char) (d + '0');
        if (res == "#" || lower(upd, res)) {
          res = upd;
        }
        continue;
    }
    int lst = 0;
    int cnt = 0;
    for (int i = 0; i <= k; ++i) {
      if (d + i < 10) ++cnt;
      lst += (d + i) % 10;
    }
    if (lst > n) continue;
    int cnt2 = (k + 1) - cnt;
    int m = n - lst;

    for (int fst = 0; fst <= m; fst += cnt) {
      int sec = m - fst;
      if (sec % cnt2) continue;
    
      int sum1 = fst / cnt, sum2 = sec / cnt2;
      int wsum1 = sum1, wsum2 = sum2;
      string upd = "";
      while (sum1 > sum2) {
        upd += "9";
        sum1 -= 9;
      }
      if (sum1 + 1 != sum2) continue;
      upd = find_one_good(sum1) + upd;
      upd += (char) ('0' + d);

      if (res == "#" || lower(upd, res)) {
        res = upd;
      }
    }
  }

  if (res == "#") {
    cout << "-1\n";
  } else {
    cout << res << "\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}