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

int n, k;
vector <int> a;
const int INF = 1e9 + 7;

struct Trie {
  struct Node {
    int L, R;
    int ans;
    int len;
  };

  vector <vector<int>> gr;
  vector <Node> nodes;

  int build(int l, int r, vector<bool>& has) {
    int v = nodes.size();
    nodes.pb(Node({-1, -1, INF, r - l}));  
    gr.pb({});
    if (r - l == 1) {
      if (has[l]) {
        nodes[v].L = nodes[v].R = 0;
      }
      return v;
    }
    int m = (l + r) / 2;
    int lson = build(l, m, has);
    int rson = build(m, r, has);
    gr[v] = {lson, rson};
    
    if (nodes[lson].L != -1) {
      nodes[v].L = nodes[lson].L; 
    } else if (nodes[rson].L != -1) {
      nodes[v].L = nodes[rson].L + nodes[lson].len;
    }

    if (nodes[rson].R != -1) {
      nodes[v].R = nodes[rson].R + nodes[lson].len;
    } else if (nodes[lson].R != -1) {
      nodes[v].R = nodes[lson].R;
    }

    nodes[v].ans = min(nodes[lson].ans, nodes[rson].ans);
    if (nodes[lson].R != -1 && nodes[rson].L != -1) {
      nodes[v].ans = min(nodes[v].ans, nodes[rson].L + nodes[lson].len - nodes[lson].R);
    }

    return v;
  }

  Trie(vector<bool>& has) {
    build(0, (1 << k), has);
  }

  void swap_dfs(int v, int h, int maxh) {
    if (h >= maxh) return;

    int lson = gr[v][0], rson = gr[v][1];
    swap_dfs(lson, h + 1, maxh);
    swap_dfs(rson, h + 1, maxh);
    swap(gr[v][0], gr[v][1]);
    swap(lson, rson);

    //per("SONS", lson, rson, nodes[lson].L, nodes[rson].L);

    if (nodes[lson].L != -1) {
      nodes[v].L = nodes[lson].L; 
    } else if (nodes[rson].L != -1) {
      nodes[v].L = nodes[rson].L + nodes[lson].len;
    } else {
      nodes[v].L = -1;
    }

    if (nodes[rson].R != -1) {
      nodes[v].R = nodes[rson].R + nodes[lson].len;
    } else if (nodes[lson].R != -1) {
      nodes[v].R = nodes[lson].R;
    } else {
      nodes[v].R = -1;
    }

    nodes[v].ans = min(nodes[lson].ans, nodes[rson].ans);
    if (nodes[lson].R != -1 && nodes[rson].L != -1) {
      nodes[v].ans = min(nodes[v].ans, nodes[rson].L + nodes[lson].len - nodes[lson].R);
    }
    //per(v, nodes[v].L, nodes[v].R, nodes[v].ans);
  }

  void print(int v = 0) {
    per(v, nodes[v].L, nodes[v].R, nodes[v].ans);
    if (!gr[v].size()) {
      return;
    }
    print(gr[v][0]);
    print(gr[v][1]);
  }
};

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  vector <bool> has((1 << k), false);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    has[x] = true;
  }

  Trie trie(has);
  vector <int> res(1 << k);
  res[0] = trie.nodes[0].ans;

  for (int x = 1; x < (1 << k); ++x) {
    int real = 0;
    for (int i = 0; i < k; ++i) {
      if (x & (1 << i)) {
        real += (1 << (k - i - 1));
      }
    }
    //per(x, real);
    for (int h = k - 1; h >= 0; --h) {
      if ((x & (1 << h)) != ((x - 1) & (1 << h))) {
        //per(h);
        trie.swap_dfs(0, 0, h + 1);
        break;
      }
    }
    res[real] = trie.nodes[0].ans;
    //trie.print();
    //per("================");
  }

  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";
}