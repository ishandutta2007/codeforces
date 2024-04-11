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
 
const int N = 1e5 + 7;
const int LOGN = 30;
const int SQ = sqrt(N);
const int SQQ = sqrt(N * LOGN);
//const int SQQ = 1;

int total[N];
int cnt[N];
ll res[N];

int vals[SQQ];
bool added[N];
 
struct Query {
  int l, r, id;
};
 
int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  cin >> n;
 
  vector <int> cntq(N, 0);
  vector <bool> is_large(N, 0);
  vector <int> large;

  vector <int> a(n);  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cntq[a[i]];
  }
  for (int i = 0; i < N; ++i) {
    if (cntq[i] >= SQQ) {
      is_large[i] = true;
      large.pb(i);
    }
  }
 
  vector <Query> qs;
 
  int q;
  cin >> q;
  
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    qs.pb({l, r, i});
  }
 
  sort(all(qs), [&](Query a, Query b) {
    if (a.l / SQ != b.l / SQ) {
      return a.l / SQ < b.l / SQ;
    }
    return a.r < b.r;
  });
 
  int l = 0, r = -1;
  for (auto now : qs) {
    while (l > now.l) {
      --l;
 
      int was = cnt[a[l]];
      --total[was];
 
      ++cnt[a[l]];
      int now = cnt[a[l]];
      ++total[now];
    }
 
    while (r < now.r) {
      ++r;
 
      int was = cnt[a[r]];
      --total[was];
 
      ++cnt[a[r]];
      int now = cnt[a[r]];
      ++total[now];
    }
 
    while (l < now.l) {
      int was = cnt[a[l]];
      --total[was];
 
      --cnt[a[l]];
      int now = cnt[a[l]];
      ++total[now];
      
      ++l;
    }
 
    while (r > now.r) {
      int was = cnt[a[r]];
      --total[was];
 
      --cnt[a[r]];
      int now = cnt[a[r]];
      ++total[now];
 
      --r;
    }

    int id = now.id;

    vector <int> d;
      
    for (int x : large) {
      if (cnt[x] >= SQQ && !added[cnt[x]]) {
        d.pb(cnt[x]);
      }
    }

    vector<int> a;
    int was = 0, ncnt = 0;
    for (int i = 1; i < SQQ; ++i) {
      vals[i] += total[i];
      if (!vals[i]) continue;
      if (ncnt) {
        res[id] += (was + i);
        --vals[i];
        if (was + i >= SQQ) {
          a.pb(was + i);
        } else {
          ++vals[was + i];
        }
      }
      res[id] += (vals[i] / 2) * (2 * i);
      if (2 * i < SQQ) {
        vals[2 * i] += vals[i] / 2;
        vals[i] %= 2;
      } else {
        while (vals[i] >= 2) {
          a.pb(2 * i);
          vals[i] -= 2;
        }
      }
      was = i, ncnt = vals[i];
      vals[i] = 0;
    }

    if (ncnt) d.pb(was);
    sort(all(d));

   /* cout << "ID: " << id << "\n";
    for (int x : d) {
      cout << x << " ";
    }
    cout << endl;*/


    int i = 0, j = 0;
    while ((d.size() - i) + (a.size() - j) > 1) {
      /*if (a.size()) {
        cout << "LAST: " << a.back() << " " << res[id] << endl;
      }*/
      if (i == d.size()) {
        int now = a[j] + a[j + 1];
        res[id] += now;
        j += 2;
        a.pb(now);
        continue;
      }
      if (j == a.size()) {
        int now = d[i] + d[i + 1];
        res[id] += now;
        i += 2;
        a.pb(now);
        continue;
      }
      int x = d[i], y = a[j];
      if (i + 1 < d.size() && d[i + 1] < y) {
        int now = d[i] + d[i + 1];
        res[id] += now;
        i += 2;
        a.pb(now);
        continue;
      }
      if (j + 1 < a.size() && a[j + 1] < x) {
        int now = a[j] + a[j + 1];
        res[id] += now;
        j += 2;
        a.pb(now);
        continue;
      }
      int now = x + y;
      res[id] += now;
      ++i, ++j;
      a.pb(now);
    }
  }
 
  for (int i = 0; i < q; ++i) {
    cout << res[i] << "\n";
  }
}