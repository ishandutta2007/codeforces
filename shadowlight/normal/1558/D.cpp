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

const int mod = 998244353;

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

const int N = 4e5 + 7;

int f[N];
int rf[N];

void init() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = bp(f[i], mod - 2);
  }
}

struct TNode {
  int x, y;
  TNode *left, *right; 
  int val;
};

TNode* new_node(int x) {
  return new TNode({x, rand(), nullptr, nullptr, 0});
}

void add_val(TNode* root, int x) {
  if (!root) return;
  root->x += x;
  root->val += x;
}

void push(TNode* root) {
  if (!root) return;
  add_val(root->left, root->val);
  add_val(root->right, root->val);
  root->val = 0;
}

TNode* merge(TNode* left, TNode* right) {
  if (!left) {
    return right;
  }
  if (!right) {
    return left;
  }
  if (left->y > right->y) {
    push(left);
    left->right = merge(left->right, right);
    return left;
  } else {
    push(right);
    right->left = merge(left, right->left);
    return right;
  }
}

pair<TNode*, TNode*> split(TNode* root, int x) {
  if (!root) {
    return {nullptr, nullptr};
  }

  push(root);
  if (root->x > x) {
    auto t = split(root->left, x);
    root->left = t.second;
    return {t.first, root}; 
  } else {
    auto t = split(root->right, x);
    root->right = t.first;
    return {root, t.second};
  }
}

int get_lst(TNode* root) {
  if (!root) {
    return 0;
  }
  if (!root->right) {
    return root->x;
  }
  push(root);
  return get_lst(root->right);
}

int get_diff(TNode* root) {
  int a = get_lst(root);
  auto t = split(root, a - 1);
  int b = get_lst(root);
  root = merge(t.first, t.second);
  return a - b;
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mult(f[n], mult(rf[k], rf[n - k]));
}

void solve() {
  int n, m;
  cin >> n >> m;

  TNode* root = new_node(n);

  vector<pair<int, int>> vals;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    vals.pb({x, y});
  }
  reverse(all(vals));
  int pr = n + 1;

  int k = 0;

  int kek = n;
  
  multiset<int> sizes;

  for (int i = 0; i < m; ++i) {
    int x = vals[i].x, cnt = vals[i].y;

    int delta = pr - x - 1;
    auto t = split(root, get_lst(root) - 1);

    while (true) {
      int a = get_lst(t.first);
      int b = get_lst(t.second);
      int diff = b - a;

      if (diff <= delta) {
        delta -= diff;
        add_val(t.second, -diff);
        t.first = split(t.first, a - 1).x;
      } else {
        add_val(t.second, -delta);
        break;
      }
    }

    root = merge(t.first, t.second);
    t = split(root, cnt);
    auto tt = split(t.first, cnt - 1);

    if (!tt.y) {
      TNode* node = new_node(cnt);
      root = merge(tt.first, merge(node, t.second));
      ++k;
    } else {
      root = merge(tt.first, merge(tt.second, t.second));
    }

    t = split(root, cnt - 1);
    add_val(t.y, -1);

    int kek = get_lst(t.x);
    if (kek == cnt - 1) {
      t.x = split(t.x, cnt - 2).x;      
    }
    root = merge(t.x, t.y);

    pr = x;
  }
  ++k;
  //per(sizes);

  int cnt = k - 1;
  int need = n - 1 - cnt;

  cout << C(n + need, need) << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}