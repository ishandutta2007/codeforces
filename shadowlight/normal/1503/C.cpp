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
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <pair<int, int> > a(n);
	vector<int> c(n);
	set <pair<int, int>> q;
	vector<int> cost(n, 0);

	ll res = 0;
	ll res2 = 0;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x >> c[i];
		res += c[i];
		res2 += c[i];
		a[i] = {x, i};
		q.insert(a[i]);
	}

	sort(all(a), [&](pair<int, int> x, pair<int, int> y) {
		if (x.x != y.x) {
			return x.x < y.x;
		}
		return c[x.y] > c[y.y];
	});
	vector <int> rindex(n);
	for (int i = 0; i < n; ++i) {
		rindex[a[i].y] = i;
		cost[i] = a[i].x + c[a[i].y];
	}
	int v = rindex[0];
	int s = rindex[0];

	while (v != n - 1) {
		if (a[v + 1].x > cost[v]) {
			res -= cost[v];
			res += a[v + 1].x;
			++v;
		} else {
			int was = cost[v];
			int ncost = cost[v];
			while ((++v) < n && a[v].x <= was) {
				ncost = max(ncost, cost[v]);
			}
			--v;
			cost[v] = ncost;
		}
	}

	v = 0;
	while (v < s) {
		if (a[v + 1].x > cost[v]) {
			res -= cost[v];
			res += a[v + 1].x;
			++v;
		} else {
			int was = cost[v];
			int ncost = cost[v];
			while ((++v) <= s && a[v].x <= was) {
				ncost = max(ncost, cost[v]);
			}
			--v;
			cost[v] = ncost;
		}
	}

	if (s && s != n - 1) {
		v = 0;
		while (v != n - 1) {
			if (a[v + 1 + ((v + 1) == s)].x > cost[v]) {
				res2 -= cost[v];
				res2 += a[v + 1 + ((v + 1) == s)].x;
				v = v + 1 + ((v + 1) == s);
			} else {
				int was = cost[v];
				int ncost = cost[v];
				while ((++v) < n && a[v].x <= was) {
					if (v == s) continue;
					ncost = max(ncost, cost[v]);
				}
				--v;
				if (v == s) {
					--v;
				}
				cost[v] = ncost;
			}
		}
		res = min(res, res2);
	}
	cout << res << "\n";
}