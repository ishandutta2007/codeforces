#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> dlcost;
vector<ll> pdcost;
vector<ll> ditems, pitems;
int k;

bool checkBread(int lim, ll s) {
	vector<ll> allItems;
	for (ll v : ditems) allItems.push_back(dlcost[lim] * v);
	for (ll v : pitems) allItems.push_back(pdcost[lim] * v);
	sort(allItems.begin(), allItems.end());
	ll checksum = 0;
	for (int i = 0; i < k; ++i) checksum += allItems[i];
	return (checksum <= s);
}

int main() {
	int n, m; ll s;
	scanf("%d %d %d %lld", &n, &m, &k, &s);
	dlcost = pdcost = vector<ll>(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &dlcost[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &pdcost[i]);
	vector<ll> dolMin(n), pouMin(n);
	for (int i = 1; i < n; ++i) {
		dlcost[i] = min(dlcost[i], dlcost[i-1]);
		pdcost[i] = min(pdcost[i], pdcost[i-1]);
		dolMin[i] = (dlcost[i] < dlcost[i-1] ? i : dolMin[i-1]);
		pouMin[i] = (pdcost[i] < pdcost[i-1] ? i : pouMin[i-1]);
		// printf("dm pm %lld %lld\n", dolMin[i], pouMin[i]);
	}
	vector<pair<int, int>> ogItems;
	for (int i = 0; i < m; ++i) {
		int t; ll c; scanf("%d %lld", &t, &c);
		ogItems.emplace_back(c, t);
		if (t == 1) ditems.push_back(c);
		else pitems.push_back(c);
	}
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		// printf("check %d\n", mid);
		if (checkBread(mid, s)) hi = mid;
		else lo = mid + 1;
	}
	if (!checkBread(lo, s)) {
		printf("-1\n");
	} else {
		printf("%d\n", lo + 1);
		for (int i = 0; i < m; ++i) {
			ogItems[i].first *= (ogItems[i].second == 1 ? dlcost[lo] : pdcost[lo]);
			ogItems[i].second = (ogItems[i].second == 1 ? i : - i - 1);
		}
		sort(ogItems.begin(), ogItems.end());
		for (int i = 0; i < k; ++i) {
			int x = ogItems[i].second;
			int id = (x < 0 ? -x - 1 : x);
			int day = (x >= 0 ? dolMin[lo] : pouMin[lo]);
			printf("%d %d\n", id + 1, day + 1);
		}
	}
	return 0;
}