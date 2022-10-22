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

vector <pair<int, int>> t;
int n, p;

struct Tree {
  int n;
  vector <int> t;

  Tree(int n) : n(n), t(2 * n, 0) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = 1;
    }
    for (int v = n - 1; v > 0; --v) {
      t[v] = t[2 * v] + t[2 * v + 1];
    }
  }

  void change(int v, int x) {
    v += n;
    t[v] = x;
    v /= 2;
    while (v) {
      t[v] = t[2 * v] + t[2 * v + 1];
      v /= 2;
    }
  }

  int get(int l, int r) {
    int sum = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        sum += t[l++];
      }
      if (r % 2 == 0) {
        sum += t[r--];
      }
    }
    return sum;
  }
};

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, p;
  cin >> n >> p;

  t.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> t[i].x;
    t[i].y = i;
  }

  sort(all(t));
  vector <ll> res(n);

  int now = 0;
  set <int> q;
  ll tm = 0;

  Tree tree(n);
  while (now < n || q.size()) {
    if (!q.size()) {
      int value = t[now].x;
      while (now < n && value == t[now].x) {
        q.insert(t[now].y);
        ++now;
      }
      tm = value;
    }
    int pos = *q.begin();
    q.erase(pos);
    tree.change(pos, 0);

    queue<int> que;
    que.push(pos);
    while (que.size()) {
      int v = que.front();

      //per(q, tm);
      
      res[v] = tm + p;
      que.pop();
      while (now < n && t[now].x <= tm + p) {
        if (tree.get(0, t[now].y - 1) == t[now].y) {
          que.push(t[now].y);
          tree.change(t[now].y, 0);
        } else {
          q.insert(t[now].y);
        }
        ++now;
      }
      tree.change(v, 1);
      tm += p;

      while (q.size()) {
        int v = *q.begin();
        if (tree.get(0, v - 1) == v) {
          que.push(v);
          tree.change(v, 0);
          q.erase(v);
        } else {
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
}