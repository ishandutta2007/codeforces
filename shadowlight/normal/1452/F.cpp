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
 freopen("O_input.txt", "r", stdin);
 //freopen("O_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 int n, q;
 cin >> n >> q;
 vector <int> cnt(n);
 for (int i = 0; i < n; ++i) {
  cin >> cnt[i];
 }

 for (int i = 0; i < q; ++i) {
  int tp;
  cin >> tp;
  if (tp == 1) {
    int pos, val;
    cin >> pos >> val;
    cnt[pos] = val;
    continue;
  }

  int x;
  ll k;

  cin >> x >> k;
  ll start = 0;
  ll total = 0;
  ll reserved = 0;

  for (int i = 0; i < n; ++i) {
    total += (1LL << i) * cnt[i];
    if (i <= x) {
      start += cnt[i];
      reserved += ((1LL << i) - 1) * cnt[i];
    }
  }
  if (total < k) {
    cout << "-1\n";
    continue;
  }
  if (start >= k) {
    cout << "0\n";
    continue;
  }
  
  ll need = k - start;
  ll res = 0;
  for (int i = x + 1; i < n; ++i) {
    ll kekw = (1LL << (i - x));
    if (cnt[i] * kekw <= need) {
      need -= cnt[i] * kekw;
      res += cnt[i] * (kekw - 1);
      reserved += cnt[i] * kekw * ((1LL << x) - 1);
      continue;
    } 
    ll t = need / kekw;
    assert(t < cnt[i]);
    need -= t * kekw;
    res += t * (kekw - 1);
    reserved += t * kekw * ((1LL << x) - 1);

    ll pr = 1;
    for (int j = i - 1; j > x; --j) {
      if (reserved >= need) break;

      ll kekw = (1LL << (j - x));
      ll t = need / kekw;
      assert(t < 2);

      need -= t * kekw;
      res += t * (kekw - 1 + pr);
      reserved += t * kekw * ((1LL << x) - 1);

      if (t) {
        pr = 1;
      } else {
        ++pr;
      }
    } 
    if (reserved < need) {
      assert(need == 1 && !reserved);
      res += pr;
      need = 0;
    }
  }

  cout << need + res << "\n";
 }
}