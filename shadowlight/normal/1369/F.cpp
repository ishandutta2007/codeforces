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
 
bool can_lose(ll s, ll t);
bool can_win(ll s, ll t);
 
bool can_win(ll s, ll t) {
  if (2 * s > t) {
    return s % 2 != t % 2;
  }
  if (t % 2 == 0) {
    return can_lose(s, t / 2);
  }
 
  return can_win(s, t / 2 + (1 - (t / 2) % 2));
}
 
bool can_lose(ll s, ll t) {
  if (2 * s > t) {
    return true;
  }
  return can_win(s, t / 2);
}
 
int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
 
  int t;
  cin >> t;
 
  int res = 1;
 
  for (int i = 0; i < t; ++i) {
    ll a, b;
    cin >> a >> b;
    
    bool win = can_win(a, b);
    bool lose = can_lose(a, b);
 
    //per(a, b, res, win, lose);
 
    if (win == lose) {
      if (!win) {
        res ^= 1;
      }
      cout << res << " " << res << "\n";
      return 0;
    }
    if (win) {
      res ^= 1;
    }
  }
  res ^= 1;
 
  cout << res << " " << (res ^ 1) << "\n";
}