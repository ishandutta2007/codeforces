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

int n;
vi g[200010];
int ch[200010];
int ret = 300000;
multiset<int> tc[200010];
set<int> vr[200010];
int aj[200010];

void pre(int v, int p)
{
	ch[v] = -1;
	int u = -1;

	for (int to : g[v]) if (to != p) {
		pre(to, v);
		aj[v]++;

		if (ch[to] != -1) {
			tc[v].insert(ch[to] + 1);
			vr[v].insert(ch[to] + 1);

			if (u == -1) {
				u = ch[to] + 1;
			} else {
				if (u != ch[to] + 1) {
					u = -2;
				}
			}
		} else {
			u = -2;
		}
	}

	if (u == -1) ch[v] = 0;
	else if (u > 0) ch[v] = u;
}

void calc(int v, int p, int chp) //ng=(chp=-2)
{
	//printf("deb:%d,%d\n", v, chp);

	if (p == -1) {
		if (tc[v].size() == aj[v] && vr[v].size() <= 2) {
			int u = 0;
			for (const int x : vr[v]) {
				u += x;
			}
			while (u % 2 == 0) {
				u /= 2;
			}
			ret = min(ret, u);
			//printf("deb:%d,%d\n", v, u);
		}
	} else {
		if (tc[v].size() == aj[v] && vr[v].size() <= 2 && chp != -2) {
			set<int> ss;

			for (const int x : vr[v]) {
				ss.insert(x);
			}

			ss.insert(chp);

			if (ss.size() <= 2) {
				int u = 0;
				for (const int x : ss) {
					u += x;
				}
				while (u % 2 == 0) {
					u /= 2;
				}
				ret = min(ret, u);

				//printf("deb:%d,%d\n", v, u);
			}
		}
	}

	for (int to : g[v]) if (to != p) {
		int x = ch[to] + 1;
		bool f = ch[to] != -1;

		if (f) {
			tc[v].erase(tc[v].lower_bound(x));

			if (!tc[v].count(x)) {
				vr[v].erase(x);
			}
		}

		int nc = chp;
		if (chp != -2) {
			if (vr[v].size() >= 2 || (int)tc[v].size() != aj[v] - 1) {
				nc = -2;
			} else {
				if (tc[v].size()) {
					if (chp == -1) {
						nc = *tc[v].begin() + 1;
					} else {
						if (chp != *tc[v].begin()) {
							nc = -2;
						} else {
							nc = chp + 1;
						}
					}
				} else {
					if (chp == -1) {
						nc = 1;
					} else ++nc;
				}
			}
		}

		calc(to, v, nc);

		if (f) {
			tc[v].insert(x);
			vr[v].insert(x);
		}
	}
}

int main() {
	scanf("%d", &n);

	rep(i, n-1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}

	int rt = 0;
	pre(rt, -1);
	//rep(i, n) cout << i << " " << ch[i] << endl;
	calc(rt, -1, -1);
	
	if (ret == 300000) ret = -1;
	printf("%d\n", ret);

	return 0;
}