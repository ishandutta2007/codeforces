#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], n;
ll fen[MAXN];
map<int, int> cnt, O, S;
vector<pair<pll, int>> H;
vector<int> ans;

inline void Add(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

inline void Add(int L, int R, int val) {
	if (R < L) return;
	Add(L, val);
	Add(R + 1, -val);
	H.push_back({{L, R}, val});
}

bool Query(int ind) {
	for (++ind; ind > 0; ind -= ind & -ind) if (fen[ind]) return true;
	return false;
}

inline void Ans(int t1, int t2) {
	ans.push_back(t1);
	ans.push_back(t2);
	ans.push_back(t1);
	ans.push_back(t2);
	H.clear();
	O.clear();
	S.clear();
	cnt.clear();	
}

bool Check_Seg(int O_ind, int x) {
	if (Query(O_ind)) {
		for (auto e : H) {
			if (O_ind >= e.X.X && O_ind <= e.X.Y) {
				Ans(e.Y, x);
				return true;
			}
		}

	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (cnt[x] >= 3) Ans(x, x);
		else if (cnt[x] == 0) {
			cnt[x]++;
			O[x] = i;
		} else if (cnt[x] == 1) {
			int O_ind = O[x];
			if (!Check_Seg(O_ind, x)) {
				cnt[x]++;
				S[x] = i;
				Add(O_ind + 1, i - 1, x);
			}
		} else {
			if (!Check_Seg(O[x], x) && !Check_Seg(S[x], x)) {
				cnt[x]++;
				Add(O[x] + 1, i - 1, x);
			}
		}
	}
	
	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}