#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 200010;

// 1-indexed, [1, n]
template<class T>
class BIT {
	T bit[300010];
	int n;

public:
	BIT() {
		n = MN;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		++i;
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int n;
ll T;
int a[MN], t[MN];
int id[MN];
vi va[MN];
bool f[MN];
BIT<int> T1, T2;

int main() {
	cin >> n >> T;

	vector<pii> vec(n);

	rep(i, n) {
		cin >> a[i] >> t[i];
		vec[i] = mp(t[i], i);
		va[a[i]].pb(i);
	}

	sort(ALL(vec));

	rep(i, n) {
		id[vec[i].se] = i + 1;
	}

	for (int i = n; i >= 1; --i) {
		for (int p : va[i]) {
			int pos = id[p];
			T1.add(pos, 1);
			f[pos] = 1;
			T2.add(pos, t[p]);
		}

		int lo = 0, hi = n;
		if (T2.sum(n) <= T) {
			lo = n;
		}

		while (hi - lo > 1) {
			int m = (lo + hi) / 2;
			if (T2.sum(m) > T) {
				hi = m;
			} else {
				lo = m;
			}
		}

		if (T1.sum(lo) >= i) {
			cout << i << endl;
			cout << i << endl;

			int zan = i;
			rep(j, MN) {
				if (zan && f[j]) {
					printf("%d%c", vec[j-1].se + 1, zan == 1 ? '\n' : ' ');
					--zan;
				}
			}
			return 0;
		}
	}

	//0
	puts("0");
	puts("0");
	puts("");

	return 0;
}