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
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> p(n);

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }

  vector<vector<pair<int, int>>> gr(n);
  vector<int> res;

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    gr[x].pb({y, i});
    gr[y].pb({x, i});
  }
  vector<bool> used(n, false);
  vector<int> pos(n, -1);

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    vector<int> order;
    while (!used[i]) {
      order.pb(i);
      pos[i] = order.size() - 1;
      used[i] = true;
      i = p[i];
    }
    int k = order.size();
    vector<vector<pair<int, int>>> edges(k);
    vector<int> to(k, 0);
    vector<int> val(k, -1);
    queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
      int x = order[i];
      for (auto [y, num] : gr[x]) {
        int a = pos[x], b = pos[y];
        int cnt = b - a;
        if (cnt < 0) cnt += k;
        edges[i].pb({cnt, num});
      }

      sort(all(edges[i]));
      if (to[i] != edges[i].size()) {
        val[i] = (i + edges[i][to[i]].x) % k;
        if (val[val[i]] == i) {
          //per(i, val[i]);
          q.push({i, edges[i][to[i]].y});
        }
      }
    }
    //per(val);
    while (!q.empty()) {
      auto [x, numx] = q.front();
      q.pop();
      res.pb(numx);

      auto [y, numy] = edges[x][to[x]];
      y = (x + y) % k;
      ++to[x], ++to[y];
      assert(numx == numy);


      if (to[x] != edges[x].size()) {
        val[x] = (x + edges[x][to[x]].x) % k;
        if (val[val[x]] == x) {
          q.push({x, edges[x][to[x]].y});
        }
      } else {
        val[x] = -1;
      }
      if (to[y] != edges[y].size()) {
        val[y] = (y + edges[y][to[y]].x) % k;
        if (val[val[y]] == y) {
          q.push({y, edges[y][to[y]].y});
        }
      } else {
        val[y] = -1;
      }
      //per(val);
    }
  }

  //per(res);

  assert(res.size() == m);
  for (auto t : res) {
    cout << t + 1 << " ";
  }
  cout << "\n";

}