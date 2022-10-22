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

vector <string> forb = {"0011", "0101", "1110", "1111"};

// It's strictly forbidden to use buildSA() and not 
// to add a fictitious integer, which should be smaller 
// than all other integers representing a string, to the end!!!
struct SuffixArray {
    static const int SZ = 3e5;

    int c[SZ];
    int cnt[SZ];
    int p[SZ];
    int pn[SZ];
    int cn[SZ];

    vector<int> buildSA(const vector<int>& s) {
        int n = s.size();
        int alpha = (*max_element(s.begin(), s.end())) + 1;
        memset(cnt, 0, alpha * sizeof(int));
        for (int c : s) ++cnt[c];
        for (int i = 1; i < alpha; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int cs = 1;
        for (int i = 1; i < n; ++i) {
            if (s[p[i]] != s[p[i - 1]]) ++cs;
            c[p[i]] = cs - 1;
        }

        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; ++i) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += n;
            }
            memset(cnt, 0, cs * sizeof(int));
            for (int i = 0; i < n; ++i) ++cnt[c[pn[i]]];
            for (int i = 1; i < cs; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i) p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            cs = 1;
            for (int i = 1; i < n; ++i) {
                int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i-1] + (1 << h)) % n;
                if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2]) ++cs;
                cn[p[i]] = cs - 1;
            }
            memcpy (c, cn, n * sizeof(int));
        }

        vector<int> result(p, p + n);
        return result;
    }

    // suf = sa from func above
    vector<int> buildLCP(const vector<int>& s, const vector<int>& suf) const {
        int n = s.size();
        vector<int> rsuf(n);
        vector<int> lcp(n);
        for (ll i = 0; i < n; i++) {
            rsuf[suf[i]] = i;
        }

        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (k > 0) --k;
            if (rsuf[i] == n - 1) {
                lcp[n - 1] = -1;
                k = 0;
                continue;
            } else {
                int j = suf[rsuf[i] + 1];
                while (max(i + k, j + k) < n && s[i + k] == s[j + k]) ++k;
                lcp[rsuf[i]] = k;
            }
        }

        return lcp;
    }
} SA;

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  string s = "";
  vector<int> val;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    val.pb(x + 1);
    s += (char) (x + '0');
  }
  val.pb(0);

  auto sa = SA.buildSA(val);
  auto lcp = SA.buildLCP(val, sa);

  //per(sa);
  //per(lcp);

  vector <vector <int>> dp(n, vector <int>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
  }

  for (int len = 1; len <= n; ++len) {
    for (int l = 0; l < n; ++l) {
      int r = l + len;
      if (r > n) break;
      
      for (int cnt = 1; cnt <= 4; ++cnt) {
        if (cnt > len) break;

        if (cnt == 4) {
          bool bad = false;
          for (auto t : forb) {
            if (s.substr(r - cnt, 4) == t) {
              bad = true;
            }
          }
          if (bad) continue;
        }

        add(dp[l][r], dp[l][r - cnt]);
      }
    }
  }

  vector<vector<int>> sums(n, vector<int>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      add(sums[i][j], sums[i][j - 1]);
      add(sums[i][j], dp[i][j]);
    }
  }

  for (int len = 1; len <= n; ++len) {
    int i = 1;
    while (sa[i] >= len) ++i;

    int res = sums[sa[i]][len];

    int cur = len - sa[i];
    for (; i < n; ++i) {
      cur = min(cur, lcp[i]);
      //updated = min(updated, lcp[i]);
      if (sa[i + 1] < len) {
        int lenw = min(cur, len - sa[i + 1]);

        add(res, sums[sa[i + 1]][len]);
        dec(res, sums[sa[i + 1]][sa[i + 1] + lenw]);

        cur = max(cur, len - sa[i + 1]);
      }
    }

    cout << res << "\n";
  }
}