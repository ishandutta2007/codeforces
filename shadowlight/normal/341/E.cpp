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

const int LOGN = 20;
const int N = 1007;

set<int> boxes[LOGN];
vector<int> sizes;
int n;

vector<pair<int, int>> res;

int get_deg(int sz) {
  if (!sz) {
    return -1;
  }
  int k = 0;
  while (sz % 2 == 0) {
    sz /= 2;
    ++k;
  }
  return k;
}

int total = 0;

void put(int a, int b) {
  if (sizes[a] < sizes[b]) {
    swap(a, b);
  }
  res.pb({b, a});

  int wha = get_deg(sizes[a]), whb = get_deg(sizes[b]);
  boxes[wha].erase(a);
  boxes[whb].erase(b);

  sizes[a] -= sizes[b];
  sizes[b] *= 2;

  wha = get_deg(sizes[a]), whb = get_deg(sizes[b]);
  if (wha != -1) {
    boxes[wha].insert(a);
  } else {
    --total;
  }
  boxes[whb].insert(b);
}

void mega_put() {
  for (int i = 0; i < LOGN; ++i) {
    if (boxes[i].size() >= 2) {
      put(*boxes[i].begin(), *boxes[i].rbegin());
      return;
    }
  }

  if (!boxes[0].size()) {
    for (int t = 1; t < LOGN; ++t) {
      if (boxes[t].size()) {
        int a = *boxes[t].begin();
        sizes[a] /= 2;
        boxes[t].erase(a);
        boxes[t - 1].insert(a);
      }
    }
    return;
  }

  for (int t = LOGN - 1; t >= 0; --t) {
    if (!boxes[t].size()) continue;
    
    int b = *boxes[t].begin();
    int a = *boxes[0].begin();
    put(a, b);
    return;
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  sizes.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> sizes[i];
    if (sizes[i]) {
      ++total;
      int wh = get_deg(sizes[i]);
      boxes[wh].insert(i);
    }
  }

  if (total < 2) {
    cout << "-1\n";
    return 0;
  }

  while (total > 2) {
    //per(sizes);
    mega_put();
  }
  //per(sizes);

  cout << res.size() << "\n";
  for (auto t : res) {
    cout << t.x + 1 << " " << t.y + 1 << "\n";
  }

}