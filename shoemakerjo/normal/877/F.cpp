#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 100010
ll ans = 0LL;
int kab[maxn];
int kbel[maxn];
int spots[maxn];
ll nums[maxn];
ll pref[maxn];
ll curcount[maxn];
ll anses[maxn];
int l, r;
int n;
ll k;

void addLeft(int u) {
	if (kab[u] != -1) {
		ans += curcount[kab[u]];
	}
	curcount[spots[u]]+=1LL;
}

void addRight(int u) {
	if (kbel[u] != -1) {
		ans += curcount[kbel[u]];
	}
	curcount[spots[u]]+=1LL;
}

void remLeft(int u) {
	curcount[spots[u]]-=1LL;
	if (kab[u] != -1) {
		ans -= curcount[kab[u]];
	}
	
}

void remRight(int u) {
	curcount[spots[u]]-=1LL;
	if (kbel[u] != -1) {
		ans -= curcount[kbel[u]];
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		if (nums[i] == 2) nums[i] = -1;
	}
	ll cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		nums[i] *= cur;
	}
	vector<ll> vals;
	set<ll> seen;
	pref[0] = 0LL;
	vals.push_back(0);
	seen.insert(0);
	curcount[0] = 0LL;
	for (int i = 1; i <= n; i++) {
		curcount[i] = 0LL;
		pref[i] = pref[i-1] + nums[i];
		if (seen.count(pref[i]) == 0) {
			seen.insert(pref[i]);
			vals.push_back(pref[i]);
		}
	}
	sort(vals.begin(), vals.end());
	for (int i = 0; i <= n; i++) {
		spots[i] = lower_bound(vals.begin(), vals.end(), pref[i])-vals.begin();
		int up = lower_bound(vals.begin(), vals.end(), pref[i] + k)-vals.begin();
		if (up != vals.size() && vals[up] == pref[i]+k) {
			kab[i] = up;
		}
		else kab[i] = -1;

		int down = lower_bound(vals.begin(), vals.end(), pref[i]-k)-vals.begin();
		if (down != vals.size() && vals[down] == pref[i]-k) {
			kbel[i] = down;
		}
		else kbel[i] = -1;
		// cout << "i: " << spots[i] << " " << kab[i] << " " << kbel[i] << endl;
	}
	vector<tuple<int, int, int, int>> queries;
	int q;
	cin >> q;
	int curl = 0, curr = 0;
	// cout << "ANS: " << ans << endl;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		queries.push_back(make_tuple(l/sqrt(n), r, l, i));
	}
	int index;
	ans = 0LL;
	// cout << "here" << endl;
	sort(queries.begin(), queries.end());
	for (int i = 0; i < q; i++) {
		l = get<2>(queries[i]);
		l--;
		r = get<1>(queries[i]);
		index = get<3>(queries[i]);
		if (i == 0) {
			for (int j = l; j <= r; j++) {
				addRight(j);
			}
			anses[index] = ans;
			curl = l;
			curr = r;
			continue;
		}
		while (curl > l) {
			curl--;
			addLeft(curl);
		}
		while (curr < r) {
			curr++;
			addRight(curr);
			// cout << "ANS: " << ans << endl;
		}
		while (curl < l) {
			remLeft(curl);
			curl++;
		}
		while (curr > r) {
			remRight(curr);
			curr--;
		}
		anses[index] = ans;
		// cout << "ans:  " << ans << endl;
	}
	for (int i = 0; i < q; i++) {
		cout << anses[i] << '\n';
	}
	// cin >> index;


}