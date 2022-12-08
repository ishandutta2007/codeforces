#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int maxn = 100010;

int n;
ll s;

ll subtree[maxn];
vector<int> ch[maxn];


void godown(int u) {
	subtree[u] = 1LL;
	for (int v : ch[u]) {
		godown(v);
		subtree[u] += subtree[v];
	}
}

ll csum;

bool check(int mid) {
	int curval;
	for (int i = 1; i <= n; i++) {
		ch[i].clear();
	}

	curval = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < mid; j++) {

			if (curval > n) break;

			ch[i].push_back(curval);
			++curval;
		}
		if (curval > n) break;
	}

	csum = 0;
	godown(1);
	for (int i = 1; i <= n; i++) {
		// cout << mid << " at " << i << " : " << subtree[i] << endl;
		csum += subtree[i];
	}

	return csum <= s;

}


int dep[maxn];
int par[maxn];

void gd(int u, int p) {
	dep[u] = dep[p]+1;

	for (int v : ch[u]) {
		par[v] = u;
		gd(v, u);
	}
}

int guyhere[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	ll maxval = n*(n+1LL)/2;
	ll minval = 2LL*n-1LL;

	if (s > maxval || s < minval) {
		cout << "No" << endl;
		return 0;
	}

	int lo = 1;
	int hi = n-1;

	//can find the branching factor this way

	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (check(mid)) {
			//value is less than or equal to s
			hi = mid;
		}
		else {
			lo = mid+1;
			//must increase branching factor to decrease ans
		}
	}

	int bf = lo;

	// cout << "csum: " << csum << endl;

	// assert(csum <= s);

	check(bf);
	gd(1, 0);

	int tg = n+1;

	//have csum all set up
	ll maxd = dep[n];
	int vatmax ;


	bool st = false;
	for (int cd = dep[n]; cd > 1; cd--) {
		if (csum == s) break;
		tg--;

		int tp = tg;
		while (dep[tg-1] == dep[tg]) {
			tg--;
		}
		if (!st) {
			vatmax = tg;
			st = true;
		}
		guyhere[dep[tg]] = tg;

		//go from tp to tg

		for (int i = tp; i > tg; i--) {
			if (csum == s) break;

			if (maxd + 1LL - dep[i] + csum > s) {
				ll numneed = s - csum;
				int spot = guyhere[dep[i] + numneed - 1];
				par[i] = spot;
				csum = s;
				break;
			}
			else {
				par[i] = vatmax;
				vatmax = i;
				csum += maxd + 1LL - dep[i];
				maxd += 1LL;
				guyhere[maxd] = i;
			}
		}

	}

	// cout << "bf: " << bf << endl;
	assert(csum == s);

	cout << "Yes" << endl;
	for (int i = 2; i <= n; i++) {
		cout << par[i] << " ";
	}
	cout << endl;


}