#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int L = 16;
struct th {
	bitset<32768> r[16];
	vi u[2];
	th() {
		for (int i = 0; i < L; i++)
			r[i] = 0;
	}
}u[205];
th cal(th a, th b) {
	th fn;
	for (int i = 0; i < 16; i++)
		fn.r[i] = a.r[i] | b.r[i];
	for (int j = 0; j < a.u[1].size(); j++)
		for (int k = 0; k < b.u[0].size(); k++)
			if (j + k + 2 < L) 
				fn.r[j + k + 2][(a.u[1][j] << (k + 1)) + b.u[0][k]] = 1;
//	for (int j = 0; j < 4; j++)
//		cout << fn.r[2][j] << endl;
//	cout << "!!!" << endl;
	fn.u[0] = a.u[0];
//	cout << "???" << ' ' << a.u[0].size() << endl;
	int cs = fn.u[0][fn.u[0].size() - 1];
	for (int j = 0; j < b.u[0].size(); j++) {
		fn.u[0].pb((cs << (j + 1)) + b.u[0][j]);
//		cout << cs << ' ' << j << ' ' << b.u[0][j] << endl;
	}
	if (fn.u[0].size() > L)	fn.u[0].resize(L);
	
//	cout << "!!!" << endl;
	fn.u[1] = b.u[1]; 
	int us = b.u[1].size();
	cs = fn.u[1][us - 1];
	for (int j = 0; j < a.u[1].size(); j++)
		fn.u[1].pb((a.u[1][j] << us) + cs);
	if (fn.u[1].size() > L) fn.u[1].resize(L);
	return fn;
}
char inp[maxn]; 
th init() {
	int l = strlen(inp);
	th fn;
	for (int i = 0; i < l; i++) {
		int cur = 0;
		for (int j = i; j - i + 1 < L && j < l; j++) {
			cur = cur * 2 + inp[j] - '0';
			fn.r[j - i + 1][cur] = 1;
			if (i == 0) fn.u[0].pb(cur);
		}
	}
	if (fn.u[0].size() > L)	fn.u[0].resize(L);
	int cur = 0; 
	for (int j = l - 1; j >= 0; j--) {
		cur += (inp[j] - '0') * (1ll << (l - j - 1));
		fn.u[1].pb(cur);
	}
	if (fn.u[1].size() > L)	fn.u[1].resize(L);
	return fn;
}
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp);
		u[i] = init();
	}
	int m;
	cin >> m;
	for (int i = n + 1; i <= n + m; i++) {
		int x, v;
		cin >> x >> v;
		u[i] = cal(u[x], u[v]);
		int ans = L - 1;
		for (int j = 1; j < L; j++) {
			if (u[i].r[j].count() != (1 << j)) {
				ans = j - 1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}