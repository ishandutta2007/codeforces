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

	int n, k;
	cin >> n >> k;

	int need = n / (k - 1);
	if (n % (k - 1)) {
		++need;
	}

	vector <int> c(n * k);
	vector <vector<int>> pos(n);
	for (int i = 0; i < n * k; ++i) {
		cin >> c[i];
		--c[i];
		pos[c[i]].pb(i);
	}
	vector <int> iter(n, 0);
	vector <int> covered(n * k, 0);
	for (int i = 0; i < n; ++i) {
		int l = pos[i][0], r = pos[i][1];
		for (int j = l; j <= r; ++j) {
			++covered[j];
		}
	}
	int now = 0;
	while (now < n * k) {
		int lst = n * k - 1;
		while (lst >= now && covered[now] > need) {
			int cc = c[lst--];
			if (iter[cc] == k - 2 || pos[cc][iter[cc] + 1] != lst + 1) continue;

			int lt = pos[cc][iter[cc]], rt = pos[cc][iter[cc] + 1];
			if (lt <= now && now <= rt) {
				for (int a = lt; a <= rt; ++a) {
					--covered[a];
				}
				++iter[cc];
				if (now == rt) {
					++lst;
				}
				lt = pos[cc][iter[cc]];
				rt = pos[cc][iter[cc] + 1];
				for (int a = lt; a <= rt; ++a){
					++covered[a];
				}
			}
		}
		assert(covered[now] <= need);
		++now;
	}

	for (int i = 0; i < n; ++i) {
		//cout << "K: " << iter[i] << " " << k << endl;
		cout << pos[i][iter[i]] + 1 << " " << pos[i][iter[i] + 1] + 1 << "\n";
	}
}