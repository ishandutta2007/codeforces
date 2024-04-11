#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<pair<int, ll>>> tree;
vector<int> stsz;
vector<ll> wToPar;

void findSizes(int v, int p) {
	for (auto v_w : tree[v]) {
		if (v_w.first == p) {
			wToPar[v] = v_w.second;
		} else {
			findSizes(v_w.first, v);
			stsz[v] += stsz[v_w.first];
		}
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int k; scanf("%d", &k);
		tree = vector<vector<pair<int, ll>>>(2*k);
		stsz = vector<int>(2*k, 1);
		wToPar = vector<ll>(2*k, 0);
		for (int i = 0; i < 2 * k - 1; ++i) {
			int a, b; ll x; scanf("%d %d %lld", &a, &b, &x);
			tree[--a].emplace_back(--b, x);
			tree[b].emplace_back(a, x);
		}
		findSizes(0, -1);
		ll G = 0;
		for (int i = 0; i < 2 * k; ++i) {
			if (stsz[i] % 2 == 1) G += wToPar[i];
		}
		ll B = 0;
		for (int i = 0; i < 2 * k; ++i) {
			ll minCount = min(stsz[i], 2 * k - stsz[i]);
			B += wToPar[i] * minCount;
		}
		printf("%lld %lld\n", G, B);
	}
}