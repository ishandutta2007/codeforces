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

vector<int> sa;
const int INF = 1e9 + 7;

struct Tree {
  int n;
  vector <pair<int, int>> t;
  vector <int> ded;
  vector <pair<int, int>> val;
  vector <int> lcp;

  void build_tree(int v, int l, int r, vector<int>& a) {
    if (r - l == 1) {
      lcp[v] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m, a);
    build_tree(2 * v + 1, m, r, a);
    lcp[v] = min(lcp[2 * v], lcp[2 * v + 1]);
  }

  Tree(int n, vector<int>& a) : n(n), t(4 * n, {-1, -1}), val(4 * n, {-1, -1}), lcp(4 * n, -1), ded(4 * n, INF) {
    build_tree(1, 0, n, a);
  }

  void add_val(int v, pair<int, int> valt) {
    t[v] = max(t[v], valt);
    val[v] = max(val[v], valt);
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
  }

  void change(int pos, int vt, int lt, int rt) {
    if (rt - lt == 1) {
      ded[vt] = sa[pos];
      // cout << "ASS: " << pos << " " << lt << " " << rt << " " << sa[pos] << endl;
      return;
    }
    int mt = (lt + rt) / 2;
    if (pos < mt) {
      change(pos, 2 * vt, lt, mt);
    } else {
      change(pos, 2 * vt + 1, mt, rt);
    }
    ded[vt] = min(ded[2 * vt], ded[2 * vt + 1]);
  }

  void change(int pos) {
    change(pos, 1, 0, n);
  }

  bool add_right(int pos, int lcpx, int vt, int lt, int rt) {
    if (pos >= rt) {
      return true;
    }
    if (lcpx <= lcp[vt]) {
      //cout << "ASS: " << lt << " " << rt << endl;
      add_val(vt, {lcpx, -sa[pos]});
      return true;
    }

    if (rt - lt == 1) {
      //cout << "ASS: " << lt << " " << rt << endl;
      add_val(vt, {lcpx, -sa[pos]});
      return false;
    }

    push(vt);
    int mt = (lt + rt) / 2;
    bool addw = add_right(pos, lcpx, 2 * vt, lt, mt);
    if (addw) {
      return add_right(pos, lcpx, 2 * vt + 1, mt, rt);
    } else {
      return false;
    }
  }

  void add_right(int pos, int lcpx) {
    add_right(pos, lcpx, 1, 0, n);
  }

  pair <int, bool> get_right(int pos, int lcpx, int vt, int lt, int rt) {
    if (pos >= rt) {
      return {INF, true};
    }
    if (lcpx <= lcp[vt]) {
      return {ded[vt], true};
    }

    if (rt - lt == 1) {
      return {ded[vt], false};
    }

    push(vt);
    int mt = (lt + rt) / 2;
    auto [res, addw] = get_right(pos, lcpx, 2 * vt, lt, mt);
    if (addw) {
      auto t = get_right(pos, lcpx, 2 * vt + 1, mt, rt);
      res = min(res, t.x);
      addw &= t.y;
    }
    return {res, addw};
  }

  int get_right(int pos, int lcpx) {
    return get_right(pos, lcpx, 1, 0, n).x;
  }

  pair<int, bool> get_left(int pos, int lcpx, int vt, int lt, int rt) {
    //cout << "GET: " << pos << " " << lt << " " << rt << endl;
    if (pos <= lt) {
      return {INF, true};
    }

    if (lcpx <= lcp[vt]) {
      return {ded[vt], true};
    }

    if (rt - lt == 1) {
      return {INF, false};
    }

    int mt = (lt + rt) / 2;
    auto [res, addw] = get_left(pos, lcpx, 2 * vt + 1, mt, rt);
    if (addw) {
      auto t = get_left(pos, lcpx, 2 * vt, lt, mt);
      res = min(res, t.x);
      addw &= t.y;
    }
    return {res, addw};
  }

  bool add_left(int pos, int lcpx, int vt, int lt, int rt) {
    if (pos <= lt) {
      return true;
    }

    if (lcpx <= lcp[vt]) {
      //cout << "ASS: " << lt << " " << rt << endl;
      add_val(vt, {lcpx, -sa[pos]});
      return true;
    }

    if (rt - lt == 1) {
      return false;
    }

    push(vt);
    int mt = (lt + rt) / 2;
    bool addw = add_left(pos, lcpx, 2 * vt + 1, mt, rt);
    if (addw) {
      return add_left(pos, lcpx, 2 * vt, lt, mt);
    } else {
      return false;
    }
  }

  void add_left(int pos, int lcpx) {
    add_left(pos, lcpx, 1, 0, n);
  }

  int get_left(int pos, int lcpx) {
    return get_left(pos, lcpx, 1, 0, n).x;
  }

  pair<int, int> get(int pos, int vt, int lt, int rt) {
    if (rt - lt == 1) {
      return t[vt];
    }
    push(vt);
    int mt = (lt + rt) / 2;
    if (pos < mt) {
      return get(pos, 2 * vt, lt, mt);
    }
    return get(pos, 2 * vt + 1, mt, rt);
  }

  pair<int, int> get(int pos) {
    return get(pos, 1, 0, n);
  }
};

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  string s = "";

  vector <int> a;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    s += c;
    a.pb(c - 'a' + 1);
  }
  a.pb(0);
  s += "#";

  sa = SA.buildSA(a);
  auto lcp = SA.buildLCP(a, sa);

  /*for (int i = 0; i < (int) sa.size(); ++i) {
    cout << i << " " << s.substr(sa[i], s.size()) << endl;
  }*/

  vector <int> rsa(n + 1);
  for (int i = 0; i < (int) sa.size(); ++i) {
    rsa[sa[i]] = i;
  }

  /*for (int x : lcp) {
    cout << x << " ";
  }
  cout << endl;*/

  Tree tree(n + 1, lcp);

  vector <int> dp(n + 1, 1);
  int res = 0;
  for (int i = n - 1; i >= 0; --i) {
    auto [len, index] = tree.get(rsa[i]);
    index = -index;

    int nlen;

    if (len != -1) {
      int j = tree.get_right(rsa[i], len);
      j = min(j, tree.get_left(rsa[i], len));
      assert(j != INF);
      
      dp[i] = dp[index] + 1;
      nlen = len + j - i;
    } else {
      nlen = 1;
    }
    res = max(res, dp[i]);
    //cout << i << " " << dp[i] << endl;
    //cout << "FOUND: " << i << " " << rsa[i] << " " << len << " " << nlen << endl;

    tree.change(rsa[i]);
    tree.add_right(rsa[i], nlen);
    tree.add_left(rsa[i], nlen);
  }

  cout << res << "\n";
}