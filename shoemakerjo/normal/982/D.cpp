#include <bits/stdc++.h>

using namespace std;

#define maxn 100010
#define pii pair<int, int>

int nums[maxn];
int par[maxn];
int ra[maxn];
int sz[maxn];

int ct[maxn]; // number of each size

int ccs;

int findset(int u) {
	if (u == par[u]) return u;
	return par[u] = findset(par[u]);
}

void unionset(int a, int b) {
	a = findset(a);
	b = findset(b);
	if (a == b) return;
	ccs--;
	ct[sz[a]]--;
	ct[sz[b]]--;
	if (ra[a] > ra[b]) {
		par[b] = a;
		sz[a] += sz[b];
		ct[sz[a]]++;
	}
	else {
		par[a] = b;
		if (ra[a] == ra[b]) ra[b]++;
		sz[b] += sz[a];
		ct[sz[b]]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	// int nums[n];
	//activate parts one by one, check if all sections are equivalent
	vector<pii> vals;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		vals.push_back(pii(nums[i], i));
	}
	fill(ct, ct+maxn, 0);
	ccs = 0;
	sort(vals.begin(), vals.end());
	int ans = n+1;
	int mlcos = -1;
	for (pii vp : vals) {
		int vc = vp.first;
		int ind = vp.second;
		ccs++; //set up everything
		ct[1]++;
		ra[ind] = 1;
		par[ind] = ind;
		sz[ind] = 1;
		if (ind != 0 && nums[ind-1] < nums[ind]) {
			unionset(ind-1, ind);
		}
		if (ind != n-1 && nums[ind+1] < nums[ind]) {
			unionset(ind, ind+1);
		}
		ind = findset(ind);
		if (ct[sz[ind]] == ccs) {
			if (ccs > mlcos) {
				mlcos = ccs;
				ans = vc+1;
			}
			else if (ccs == mlcos) {
				ans = min(ans, vc+1);
			}
		}

	}

	cout << ans << endl;
	cin >> ans;


}