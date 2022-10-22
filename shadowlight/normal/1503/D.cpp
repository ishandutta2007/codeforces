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

const int N = 2e5 + 7;

pair <int, int> a[N];
int b[2 * N];
int ind[2 * N];
int type[2 * N];

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    b[a[i].x] = a[i].y;
    b[a[i].y] = a[i].x;
    ind[a[i].x] = ind[a[i].y] = i;
  }
  fill_n(type, 2 * N, -1);

  int res = 0;

  for (int x = 1; x <= 2 * n; ++x) {
    vector <int> visited;
    set <int> q, qq;

    int now = INF;

    if (type[x] != -1) continue;

    for (int val = 0; val < 2; ++val) {
      for (auto t : visited) {
        type[t] = -1;
      }
      visited.clear();
      
      type[x] = val;
      type[b[x]] = val ^ 1;
      visited.pb(x);
      visited.pb(b[x]);

      qq.insert(b[x]);

      int lst_mx = INF, lst_mn = -INF;
      int upd_qq = INF, upd_q = -INF;

      while (q.size() || qq.size()) {
        if (qq.size()) {
          int mx = *qq.rbegin() + 1;
          if (mx - 1 > upd_qq) {
            cout << "-1\n";
            return 0;
          }

          upd_qq = mx - 1;

          qq.erase(*qq.rbegin());
          if (type[mx] != -1) continue;
          int start = -1, last = -1;
          while (mx <= 2 * n && type[mx] == -1) {
            type[mx] = val;
            visited.pb(mx);
            int nxt = b[mx++];
            if (start == -1) {
              start = nxt;
            } else {
              if (nxt > last) {
                cout << "-1\n";
                return 0;
              }
            }
            q.insert(nxt);
            last = nxt;
            type[nxt] = val ^ 1;
            visited.pb(nxt);
          }
          if (last < lst_mn) {
            cout << "-1\n";
            return 0;
          }
          lst_mn = last;
        } else {
          int mn = *q.begin() - 1;
          if (mn + 1 < upd_q) {
            cout << "-1\n";
            return 0;
          }
          upd_q = mn + 1;

          q.erase(*q.begin());
          if (type[mn] != -1) continue;
          int start = -1, last = -1;
          while (mn >= 1 && type[mn] == -1) {
            type[mn] = val;
            visited.pb(mn);
            int nxt = b[mn--];
            if (start == -1) {
              start = nxt;
            } else {
              if (nxt < last) {
                cout << "-1\n";
                return 0;
              }
            }
            qq.insert(nxt);
            last = nxt;
            type[nxt] = val ^ 1;
            visited.pb(nxt);
          }
          if (last > lst_mx) {
            cout << "-1\n";
            return 0;
          }
          lst_mx = last;
        }
      }

      //cout << lst_mn << " " << lst_mx << " " << b[x] << endl;

      if (lst_mn >= b[x]) {
        cout << "-1\n";
        return 0;
      }

      sort(all(visited));
      int mx = INF;
      for (int x : visited) {
        if (type[x]) continue;
        if (b[x] > mx) {
          cout << "-1\n";
          return 0;
        }
        mx = b[x];
      }

      int cnt = 0;
      for (auto x : visited) {
        cnt += (a[ind[x]].y == x) == type[x];
      }
      assert(cnt % 2 == 0);
      cnt /= 2;
      now = min(now, cnt);
    }
    res += now;
  }
  cout << res << "\n";
}