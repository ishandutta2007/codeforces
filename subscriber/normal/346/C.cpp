#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
#define SS stringstream
#define pw(x) (1ll << (x))
#define m0(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a, b;
int gg[2000222];
int q[111000];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	sort(q, q + n);
	n = unique(q, q + n) - q;
	cin >> b >> a;
	for (int i = 0; i <= b - a; i++) gg[i] = 1e9+ 5;
	for (int i = 0; i < n; i++) {
		int x = q[i];
		int it = (a + x - 1) / x * x;
		while (it <= b) {
			int from = min(b, it + x - 1);
			gg[from - a] = min(gg[from - a], it);

			it += x;
		}
	}
	int pos = b;
	int u = b + 1;
	int go = 1e9 + 6;
	int ans = 0;
	while (pos != a) {
		ans++;
		while (u > pos) {
			u--;
			go = min(go, gg[u - a]);
		}
		if (go >= pos) pos--; else pos = go; 
	}
	cout << ans << endl;
	return 0;
}