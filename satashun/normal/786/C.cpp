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


const int N = 100010;

// 1-indexed, [1, n]
template<class T>
class BIT {
	T bit[N];
	int n;

public:
	BIT() {
		n = N + 10;
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

	int lowerBound(int w) {
		if (w <= 0) return 0;
		int x = 0;
		for (int k = (1 << 18); k > 0; k /= 2) {
			if (x + k <= N && bit[x + k] < w) {
				w -= bit[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};

int n;
int a[100010];
int pr[100010];
int la[100010];
int num[100010];
int ans[100010];
BIT<int> T;

int main() {
	scanf("%d", &n);
	memset(pr, -1, sizeof(pr));
	memset(la, -1, sizeof(la));

	rep(i, n) {
		scanf("%d", &a[i]);
		if (pr[a[i]] != -1) {
			la[i] = pr[a[i]];
		}
		pr[a[i]] = i;
	}

	vector<pii> vec(n);
	rep(i, n) vec[i] = mp(la[i], i);
	sort(ALL(vec));

	priority_queue<pii, vector<pii>, greater<pii>> que;
	for (int i = 1; i <= n; ++i) {
		que.push(mp(0, i));
	}

	int now = 0;

	while (!que.empty()) {
		pii p = que.top(); que.pop();
		int l = p.fi, k = p.se;

		while (now < n && vec[now].fi < l) {
			T.add(vec[now].se, 1);
			++now;
		}

		ans[k]++;
		int num = k + l;

		if (T.sum(n) <= num) {
			continue;
		}

		int r = T.lowerBound(num + 1) - 1;
		if (r < n) {
			que.push(mp(r, k));
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}

	return 0;
}