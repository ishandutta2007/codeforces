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
const int N = 20;
const int MAXN = 4e5 + 7;


int dp[1 << N];
int counts[2 * MAXN];
int bal[N], min_bal[N];
int sum[1 << N];

int lst[N][2 * MAXN];
int pr[N * (1 << N)];
int total[N * (1 << N)];

bitset<2 * MAXN> has[N];
int res[N][1 << N];

int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (char c : a[i]) {
      bal[i] += (c == '(' ? 1 : -1);
      uin(min_bal[i], bal[i]);
    }
    fill_n(lst[i], 2 * MAXN, -1);
  }
  fill_n(pr, N * (1 << N), -1);
  int was = 0;

  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) continue;
      
      int nmask = mask | (1 << i);

      sum[nmask] = bal[i] + sum[mask];
      if (sum[mask] >= 0) {
        pr[was] = lst[i][sum[mask] + 1 + MAXN];
        lst[i][sum[mask] + 1 + MAXN] = was;
        total[was++] = mask;

        has[i][sum[mask] + 1 + MAXN] = true;
      }
    }
  }
  vector <bool> bad(1 << n, false);
  for (int i = 0; i < n; ++i) {
    int bal = 0;
    for (char c : a[i]) {
      bal += (c == '(' ? 1 : -1);
      ++counts[bal + MAXN];
      if (bal < 0 && has[i][-bal + MAXN]) {
        //auto nstates = states[i][-bal + MAXN];
        int index = lst[i][-bal + MAXN];
        while (index != -1) {
          int mask = total[index];
          bad[mask] = true;
          res[i][mask] = counts[-sum[mask] + MAXN];
          index = pr[index];
        }
        has[i][-bal + MAXN] = false;
      }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i) || bad[mask]) {
        bad[mask] = false;
        continue;
      }
      res[i][mask] = counts[-sum[mask] + MAXN];
    }


    bal = 0;
    for (char c : a[i]) {
      bal += (c == '(' ? 1 : -1);
      counts[bal + MAXN] = 0;
    }
  }
  fill_n(dp, 1 << n, -1);
  dp[0] = 0;

  int ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (dp[mask] == -1) continue;

    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) continue;
      
      int nmask = mask | (1 << i);
      int over = (sum[mask] + min_bal[i] < 0);
      uax(ans, dp[mask] + res[i][mask]);
      if (!over) {
        uax(dp[nmask], dp[mask] + res[i][mask]);
      }
    }
  }
  cout << ans << "\n";
}